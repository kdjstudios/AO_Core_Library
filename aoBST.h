/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOBST_H
#define AOBST_H

#include <iostream>
#include <string>

#include "aoConstant.h"
//#include "dimension2d.h"

using namespace std;

namespace ao
{
	namespace core
	{

		//
		// BSTNode
		// (struct template)
		// ----------
		// + data:TYPE
		// + up:BSTNode<TYPE>*
		// + left:BSTNode<TYPE>*
		// + right:BSTNode<TYPE>*
		// + height:int
		// ----------
		// + BSTNode<TYPE>() {
		// + BSTNode<TYPE>( new_data:const TYPE& , new_up BSTNode* )
		// ----------
		//
		template <class TYPE>
		struct BSTNode
		{
			TYPE data;
			BSTNode<TYPE>* up;
			BSTNode<TYPE>* left;
			BSTNode<TYPE>* right;
			int height;
			BSTNode()
			{
				cout << "BSTNode()\n";
				data="";
				up=NULL;
				left=NULL;
				right=NULL;
				height=1;
			}
			BSTNode( TYPE const&new_data,BSTNode* new_up)
			{
				cout << "BSTNode(new_data,new_up)\n";
				data=new_data;
				up=new_up;
				left=NULL;
				right=NULL;
				height=1;
			}
		};
		//
		// BinarySearchTree
		// (class template)
		// ----------
		// - root:BSTNode<TYPE>*
		// - size:int
		// ----------
		// + BinarySearchTree ( )
		// + virtual ~BinarySearchTree ( )
		// + insert ( target:const string& ): RetStat
		// + search ( target:string& ): RetStat
		// + clear ( ): void
		// + getSize ( ): int
		// - ascend ( current:BSTNode<TYPE>* ): void
		// - setNodeHeight ( current:BSTNode<TYPE>* ): int
		// ----------
		//
		template <class TYPE>
		class BinarySearchTree
		{
		private:
			BSTNode<TYPE>* root;
			int size;
			void ascend(BSTNode<TYPE>* current)
			{
				cout << "ascend()\n";
				while(current!=NULL)
				{
					int dif=setNodeHeight(current);
					current=current->up;
				}
			}
			int setNodeHeight(BSTNode<TYPE>* current)
			{
				//cout << "setNodeHeight()\n";
				int highest=0;
				int dif=0;
				if(current->left!=NULL)  // if there is a left
				{
					if(current->left->height>highest)
					{
						highest=current->left->height;
					}
					dif=current->left->height;
				}
				if(current->right!=NULL)  //if there is a right
				{
					if(current->right->height>highest)
					{
						highest=current->right->height;
					}
					dif-=current->right->height;
				}
				current->height=highest+1;
				return dif;
			}
		public:
			BinarySearchTree()
			{
				cout << "BinarySearchTree()\n";
				root=NULL;
				size=0;
			}
			virtual ~BinarySearchTree()
			{
				cout << "~BinarySearchTree()\n";
				clear();
			}
			RetStat insert(string const& target)
			{
				cout << "insert(), "<<target<<"\n";
				BSTNode<TYPE> * current=root;
				BSTNode<TYPE> * node=NULL;
				while(current!=NULL)
				{
					if(target==current->data)
					{
						return DUPLICATE_ERROR;
					}
					if(target<current->data)
					{
						if(current->left==NULL)
						{
							node=new BSTNode<TYPE>(target,current);
							current->left=node;
							ascend(node);
							size++;
							return SUCCESS;
						}
						current=current->left;
					}
					else
					{
						if(current->right==NULL)
						{
							node=new BSTNode<TYPE>(target,current);
							current->right=node;
							ascend(node);
							size++;
							return SUCCESS;
						}
						current=current->right;
					}
				}
				root = new BSTNode<TYPE>(target,NULL);
				size=1;
				return SUCCESS;
			}
			RetStat search(string & target)
			{
				cout << "search(), "<<target<<"\n";
				BSTNode<TYPE> * current=root;
				BSTNode<TYPE> * node=NULL;
				while(current!=NULL)
				{
					if(target==current->data)
					{
						return SUCCESS;
					}
					node=current;
					if(target<current->data)
					{
						current=current->left;
					}
					else
					{
						current=current->right;
					}
				}

				return FAIL;
			}
			void clear()
			{
				cout << "clear()\n";
				if(root==NULL)
				{
					return;
				}
				BSTNode<TYPE> * node=root;
				//clear
				for(;;)
				{
					if(node->left!=NULL)
					{
						node=node->left;
					}
					else if(node->right!=NULL)
					{
						node=node->right;
					}
					else
					{
						cout << "clearing: " << node->data << "\n";
						BSTNode<TYPE> *next=node->up;
						if(next==NULL)
						{
							root=NULL;
							delete node;
							break;
						}
						if(next->left==node)
						{
							next->left=NULL;
						}
						else
						{
							next->right=NULL;
						}
						delete node;
						node=next;
					}
				}
				size=0;
			}
			int getSize()
			{
				cout << "getSize() "<<size<<"\n";
				return size;
			}
		};

	}
}
#endif
