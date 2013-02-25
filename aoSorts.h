/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOSORTS_H
#define AOSORTS_H
//Guessing?
#define SIZE_OF_DUMMY   10;
namespace ao
{
	namespace core
	{
		//heap sort stuff
		void SortHeapHelp(int *a, int arr_ubound)
		{
			int i,o;
			int lChild, rChild, mChild, root, temp;
			//find the root element of the current element
			root = (arr_ubound-1)/2;
			//creating the heap
			for(o=root; o>=0; o--)
			{
				cout <<"-";
				for(i=root; i>=0; i--)
				{
					cout <<"_";
					lChild = (2*i)+1;
					rChild = (2*i)+2;
					if ((lChild <= arr_ubound) && (rChild <= arr_ubound))
					{
						if(a[rChild] >= a[lChild])
							mChild = rChild;
						else
							mChild = lChild;
					}
					else
					{
						if(rChild > arr_ubound)
							mChild = lChild;
						else
							mChild = rChild;
					}
					//swap elements
					if (a[i] < a[mChild])
					{
						cout <<"+";
						temp = a[i];
						a[i] = a[mChild];
						a[mChild] = temp;
					}
				}
			}
			//move the max element to the end of the array
			temp = a[0];
			a[0] = a[arr_ubound];
			a[arr_ubound] = temp;
			return;
		}
		void heapSort(int *a, int arr_ubound)
		{
			for(int i=arr_ubound; i>1; i--)
			{
				cout <<"\n=";
				SortHeapHelp(a, i - 1);
			}
		}
		//bubble sort
		void bubbleSort(int *a, int n)
			/* Sorts in increasing order the array A of the size N */
		{
			int k;
			int bound = n-1;
			int t;
			int last_swap;

			while (bound)
			{
				cout << "\n=";
				last_swap = 0;
				for ( k=0; k<bound; k++ )
				{
					cout << "+";
					t = a[k]; /* t is a maximum of A[0]..A[k] */
					if ( t > a[k+1] )
					{
						cout << "-";
						a[k] = a[k+1];
						a[k+1] = t; /*swap*/
						last_swap = k; /* mark the last swap position */
					}//if
				}//for
				bound=last_swap; /*elements after bound already sorted */
			}//while
		} // bubbleSort
		//insert sort
		void insertSort( int *a, int n )// array to be sorted
			// size of the array; note that (n-1) is the upper index of the array
		{
			int t;
			int i, j;
			int total_comp=0,total_moves=0;
			/* Outer "boundary definition" loop */
			for (i = 1; i < n; i++)
			{
				cout << "\n=";
				if ( a[i-1]<=a[i] )
				{
					total_comp++;
					continue;
					cout << "+";
				}

				t = a[i];
				total_moves++;

				/* inner loop: elements shifted down until insertion point found  */
				for (j = i-1; j >= 0; j--)
				{
					cout << "-";
					total_comp++;
					if ( a[j] <= t )
					{
						cout << "_";
						break;
					}
					a[j+1] = a[j];
					total_moves++;
				}
				/* insert */
				a[j+1] = t;
				total_moves++;
			}

		}
		//selection sort
		void selectionSort(int *a,int n)
		{

			for(int x=0; x<n; x++)

			{
				cout << "\n=";

				int index_of_min = x;

				for(int y=x; y<n; y++)

				{
					cout << "-";

					if(a[index_of_min]>a[y])

					{
						cout << "+";

						index_of_min = y;

					}

				}

				int temp = a[x];

				a[x] = a[index_of_min];

				a[index_of_min] = temp;

			}
		}
		//merge sorting stuff
		void merge(int a[],int low,int mid,int high)
		{
			int *b=new int[high];
			int h,i,j,k;
			h=low;
			i=low;
			j=mid+1;

			while((h<=mid)&&(j<=high))
			{
				cout << "-";
				if(a[h]<=a[j])
				{
					b[i]=a[h];
					h++;
				}
				else
				{
					b[i]=a[j];
					j++;
				}
				i++;
			}
			//
			if(h>mid)
			{
				for(k=j; k<=high; k++)
				{
					b[i]=a[k];
					i++;
				}
			}
			else
			{
				for(k=h; k<=mid; k++)
				{
					b[i]=a[k];
					i++;
				}
			}
			//
			for(k=low; k<=high; k++)
			{
				a[k]=b[k];
			}
		}
		void merge_sort(int a[],int low,int high)
		{
			int mid;
			if(low<high)
			{
				cout << "\n=";
				mid=(low+high)/2;
				merge_sort(a,low,mid);
				merge_sort(a,mid+1,high);
				merge(a,low,mid,high);
			}
		}

		//quick sort
		void quickSort(int *S,int p,int r)
		{
			int temp;
			int x = S[r];
			int i = p-1;
			for(int j = p; j<r-1; r++)
			{
				temp=0;
				cout << "=";
				if (S[j] <= x)
				{
					cout << "+";
					i = i+1;
					temp=S[i];
					S[i] = S[j];
					S[j]=temp;
				}
			}
			temp=S[i+1];
			S[i+1] = S[r];
			S[r]=temp;

			//return i+1
		}

		typedef struct ItemTag
		{
			int	Key;
			int	InitialIndex;
			int	dumy[SIZE_OF_DUMMY];
		} Item;

		int ItemCompare( const void* item1 , const void* item2 )
		{
			return ((const Item*)item1)->Key-((const Item*)item2)->Key;
		}

		typedef int (*fncompare)( const void* , const void* );
		void MergeSortLeft( unsigned char* unsorted , unsigned char* sorted , size_t length , size_t width , fncompare func );
		void MergeSortRight( unsigned char* unsorted , unsigned char* sorted , size_t length , size_t width , fncompare func );

		void Merge( unsigned char* buffer , unsigned char* frontFirst , unsigned char* frontLast ,
			unsigned char* rearFirst , unsigned char* rearLast , size_t width , fncompare func )
		{

			for (; frontFirst != frontLast && rearFirst != rearLast; buffer+=width)
			{
				if (func(rearFirst,frontFirst) < 0)
				{
					memcpy(buffer,rearFirst,width);
					rearFirst+=width;
				}
				else
				{
					memcpy(buffer,frontFirst,width);
					frontFirst+=width;
				}
			}
			if (frontFirst == frontLast)
			{
				frontFirst=rearFirst;
				frontLast=rearLast;
			}
			memcpy(buffer,frontFirst,frontLast-frontFirst);

		}
		// sorted elements will be stored in "unsorted"
		void MergeSortLeft( unsigned char* unsorted , unsigned char* sorted , size_t length , size_t width , fncompare func )
		{
			unsigned char*	unsortedMiddle=unsorted+length/2*width;
			unsigned char*	sortedMiddle=sorted+length/2*width;

			if (length < 2) return;

			MergeSortRight(unsorted,		sorted,			length/2,			width,	func);
			MergeSortRight(unsortedMiddle,	sortedMiddle,	length-length/2,	width,	func);

			Merge(unsorted,sorted,
				sortedMiddle,
				sortedMiddle,
				sorted+length*width,
				width,func);

		}



		// sorted elements will be stored in "sorted"
		void MergeSortRight( unsigned char* unsorted , unsigned char* sorted , size_t length , size_t width , fncompare func )
		{
			unsigned char*	unsortedMiddle=unsorted+length/2*width;
			unsigned char*	sortedMiddle=sorted+length/2*width;

			if (length == 0) return;
			if (length == 1)
			{
				memcpy(sorted,unsorted,width);
			}

			MergeSortLeft(unsorted,			sorted,			length/2,			width,	func);
			MergeSortLeft(unsortedMiddle,	sortedMiddle,	length-length/2,	width,	func);

			Merge(sorted,unsorted,
				unsortedMiddle,
				unsortedMiddle,
				unsorted+length*width,
				width,func);

		}



		void MergeSort( void* a, size_t count , size_t width , fncompare func )
		{
			void*	temp=NULL;

			temp=malloc(count*width);
			if (temp)
			{
				MergeSortLeft(a,temp,count,width,func);
				free(temp);
			}
		}



		void MergeSort2( void* original, size_t count , size_t width , fncompare func )
		{
			size_t			length=0;// legnth of each division
			size_t			lwidth=0;
			unsigned char*	left=0;
			unsigned char*	left_end=0;
			unsigned char*	right=0;
			unsigned char*	right_end=0;
			unsigned char*	copied=0;
			unsigned char*	end_point=0;
			void*			temp=0;
			unsigned char*	a=0;
			unsigned char*	b=0;

			a=original;
			b=malloc(count*width);
			if (!b) return;

			for (length=1; length < count; length+=length)
			{

				right_end=a;
				copied=b;

				end_point=(unsigned char*)a+count*width;

				lwidth=length*width;

				while (right_end != end_point)
				{

					left=right_end;
					left_end=left+lwidth;
					if (left_end > end_point) left_end=end_point;

					right=left_end;
					right_end=right+lwidth;
					if (right_end > end_point) right_end=end_point;

					for (; left != left_end && right != right_end; copied+=width)
					{
						if (func(right,left) < 0)
						{
							memcpy(copied,right,width);
							right+=width;
						}
						else
						{
							memcpy(copied,left,width);
							left+=width;
						}
					}

					if (left != left_end)
					{
						memcpy(copied,left,(left_end-left));
						copied+=(left_end-left);
					}
					else if (right != right_end)
					{
						memcpy(copied,right,(right_end-right));
						copied+=(right_end-right);
					}

				}

				// swap a and b
				temp=a;
				a=b;
				b=temp;
			}

			// copy everything back if b is original
			if (b == original)
			{
				memcpy(b,a,width*count);
				free(a);
			}
			else free(b);
		}


		void OptimizedMergeSort( void* original, size_t count , size_t width , fncompare func )
		{
			size_t			length=0;// legnth of each division
			size_t			lwidth=0;
			unsigned char*	left=0;
			unsigned char*	left_end=0;
			unsigned char*	right=0;
			unsigned char*	right_end=0;
			unsigned char*	copied=0;
			unsigned char*	end_point=0;
			void*			temp=0;
			unsigned char*	a=0;
			unsigned char*	b=0;

			a=original;
			b=malloc(count*width);
			if (!b) return;

			end_point=(unsigned char*)a+count*width;

			lwidth=8*width;

			right_end=a;
			while (right_end != end_point)
			{

				left=right_end;
				right_end+=lwidth;

				if (right_end > end_point) right_end=end_point;

				for (right=left+width; right < right_end; right+=width)
				{
					if (func(right,right-width) < 0)
					{
						memcpy(b,right,width);
						left_end=right;
						do
						{
							left_end-=width;
						}
						while (left_end > (unsigned char*)left && func(right,left_end-width) < 0);
						memmove(left_end+width,left_end,right-left_end);
						memcpy(left_end,b,width);
					}
				}
			}

			for (length=8; length < count; length+=length)
			{

				right_end=a;
				copied=b;

				end_point=(unsigned char*)a+count*width;

				lwidth=length*width;

				while (right_end != end_point)
				{

					left=right_end;
					left_end=left+lwidth;
					if (left_end > end_point) left_end=end_point;

					right=left_end;
					right_end=right+lwidth;
					if (right_end > end_point) right_end=end_point;

					for (; left != left_end && right != right_end; copied+=width)
					{
						if (func(right,left) < 0)
						{
							memcpy(copied,right,width);
							right+=width;
						}
						else
						{
							memcpy(copied,left,width);
							left+=width;
						}
					}

					if (left != left_end)
					{
						memcpy(copied,left,(left_end-left));
						copied+=(left_end-left);
					}
					else if (right != right_end)
					{
						memcpy(copied,right,(right_end-right));
						copied+=(right_end-right);
					}

				}

				// swap a and b
				temp=a;
				a=b;
				b=temp;
			}

			// copy everything back if b is original
			if (b == original)
			{
				memcpy(b,a,width*count);
				free(a);
			}
			else free(b);
		}

	}
}
#endif
