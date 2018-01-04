/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOLISTS_H
#define AOLISTS_H
#include <cassert>
namespace ao
{
	namespace core
	{
		//
		// ListN
		// (class template)
		// ----------
		// + isEmpty:TYPE
		// + isFull:BSTNode<TYPE>*
		// + getLength:BSTNode<TYPE>*
		// + getMaxSize:BSTNode<TYPE>*
		// + InsertAt(const TYPE& t, int pos):int
		// ----------
		// + ~ListN()
		// + ListN(int listSize=10)
		// ----------
		// - m_MaxSize:int
		// - m_Length:int
		// - m_List:TYPE*
		//
		template<class TYPE> class ListN
		{
		public:
			bool isEmpty()const
			{
				return (m_Length==0);
			}
			bool isFull()const
			{
				return (m_Length==m_MaxSize);
			}
			int getLength()const
			{
				return m_Length;
			}
			int getMaxSize()const
			{
				return m_MaxSize;
			}
			//void sort();
			//void print() const;
			void InsertAt(const TYPE& t, int pos)
			{
				assert(pos>=0&&pos<m_MaxSize);
				m_List[pos]=t;
				m_Length++;
			}
			ListN(int listSize=10)
			{
				m_MaxSize=listSize;
				m_Length=0;
				m_List=new TYPE[m_MaxSize];
			}
			~ListN()
			{
				delete [] m_List;
			}
		private:
			int m_MaxSize;
			int m_Length;
			TYPE * m_List;
		};
		//
		// List
		// (abstract base class)
		// ----------
		// # size:int
		// ----------
		// + List ( )
		// + ~List ( )
		// + getElement ( index:int, result:TYPE& ): RetStat
		// + setElement ( index:int, result:const TYPE& ): RetStat
		// + getSize ( ): int
		// ----------
		//
		template <class TYPE>class ListAbstract
		{
		protected:
			int size;
		public:
			ListAbstract()
			{
				cout << "List()\n";
			}
			~ListAbstract()
			{
				cout << "~List()\n";
			}
			virtual RetStat getElement(int index, TYPE& result)=0;
			virtual RetStat setElement(int index,const  TYPE& result)=0;
			int getSize()
			{
				return size;
			}
		};
		//
		// ContiguousList
		// (derives from List)
		// ----------
		// - array:TYPE*
		// - size:int
		// ----------
		// + ContiguousList ( )
		// + ContiguousList ( max:int )
		// + ~ContiguousList ( )
		// + getElement ( index:int, result:TYPE& ): RetStat
		// + setElement ( index:int, result:const TYPE& ): RetStat
		// ----------
		//
		template <class TYPE>class ContiguousList : public ListAbstract<TYPE>
		{
		private:
			TYPE* array;
			int size;
		public:
			ContiguousList()
			{
				array= new TYPE[10];
				size=10;
			}
			ContiguousList(int max)
			{
				if(max<2)
				{
					max=2;
				}
				array= new TYPE[max];
				size=max;
			}
			~ContiguousList()
			{
				delete [] array;
			}
			RetStat getElement(int index, TYPE& result)
			{
				if((index<0)||(index>=size))
				{
					return FAIL;
				}
				result=array[index];
				return SUCCESS;
			}
			RetStat setElement(int index,const TYPE& result)
			{
				if((index<0)||(index>=size))
				{
					return FAIL;
				}
				array[index]=result;
				return SUCCESS;
			}
		};
		//
		// Vector
		// (derives from List)
		// ----------
		// - array:TYPE*
		// - size:int
		// - alloc:int
		// ----------
		// + Vector ( )
		// + Vector ( max:int )
		// + ~Vector ( )
		// + getElement ( index:int, result:TYPE& ): RetStat
		// + setElement ( index:int, result:const TYPE& ): RetStat
		// + pushBack ( result:const TYPE& ): RetStat
		// ----------
		//
		//
		template <class TYPE>class VectorN: public ListAbstract<TYPE>
		{
		private:
			TYPE*array;
			int size;
			int alloc;
		public:
			VectorN()
			{
				array= new TYPE[10];
				size=0;
				alloc=10;
			}
			VectorN(int max)
			{
				if(max<2)
				{
					max=2;
				}
				array=new TYPE[max];
				size=max;
				alloc=max;
			}
			~VectorN()
			{
				delete [] array;
			}
			RetStat getElement(int index,TYPE&result)
			{
				if((index<0)||(index>=size))
				{
					return FAIL;
				}
				result=array[index];
				return SUCCESS;
			}
			RetStat setElement(int index,TYPE const &result)
			{
				if(size>=alloc)
				{
					// create a new array that is twice as big
					cout << "pushBack(" << result.c_str() << "):  size=" << size << " oldAlloc=" << alloc  << "  newAlloc=" << (alloc*2) << endl;
					TYPE * newArray=new TYPE[alloc*2];
					// copy the contents of array[] into newArray[]
					for(int index=0; index<alloc; index++)
					{
						newArray[index]=array[index];
					}
					// null values for new alloc
					for(int index=alloc; (index<alloc*2); index++)
					{
						newArray[index]="";
					}
					// delete the old and replace with new
					delete [] array;
					array=newArray;
					alloc*=2;
				}
				else
				{
					cout << "pushBack(" << result.c_str() << ")\n";
				}
				// save the new data at the end of array[] and bump the size
				array[size]=result;
				size++;
				return SUCCESS;
			}
			/*
			RetStat pushBack(TYPE const &result)
			{
				//if((index<0)||(index>=size)) {
				//	return FAIL;
				//}
				array[index]=result;
				return SUCCESS;
			}
			*/
		};

	}
}
#endif
