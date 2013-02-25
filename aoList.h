/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOLIST_H
#define AOLIST_H

#include <iostream>
#include <string>

#include "aoConstant.h"
//#include "dimension2d.h"

using namespace std;

namespace ao
{
	namespace core
	{

		// UML Class Definitions:
		//
		// List
		// (abstract base class)
		// ----------
		// # size:int
		// ----------
		// + List ( )
		// + ~List ( )
		// + getElement ( index:int, result:string& ): RetStat
		// + setElement ( index:int, result:const string& ): RetStat
		// + getSize ( ): int
		// ----------
		//
		class List
		{
		protected:
			int size;
		public:
			List()
			{
				cout << "List()\n";
			}
			~List()
			{
				cout << "~List()\n";
			}
			virtual RetStat getElement(int index, string& result)=0;
			virtual RetStat setElement(int index,const  string& result)=0;
			int getSize()
			{
				return size;
			}
		};
		//
		// DoublyLinkedNode
		// ----------
		// + key:string
		// + next:DoublyLinkedNode*
		// + previous:DoublyLinkedNode*
		// ----------
		// + DoublyLinkedNode ( key:string )
		// + ~DoublyLinkedNode ( )
		// ----------
		//
		class DoublyLinkedNode
		{
		public:
			string key;
			DoublyLinkedNode* next,*previous;
			DoublyLinkedNode()
			{
				cout << "DoublyLinkedNode()\n";
				key="";
				next=NULL;
				previous=NULL;
			}
			DoublyLinkedNode(string newKey)
			{
				cout << "DoublyLinkedNode() : "<<newKey.c_str()<<"\n";
				key=newKey;
				next=NULL;
				previous=NULL;
			}
		};
		//
		// DoublyLinkedList
		// (derives from List)
		// ----------
		// - front:DoublyLinkedNode*
		// - back:DoublyLinkedNode*
		// ----------
		// + DoublyLinkedList ( )
		// + ~DoublyLinkedList ( )
		// + getElement ( index:int, key:string& ): RetStat
		// + setElement ( index:int, key:const string& ): RetStat
		// + pushBack ( key:const string& ) : RetStat
		// + pushFront ( key:const string& ) : RetStat
		// + popBack ( key:string& ) : RetStat
		// + popFront ( key:string& ) : RetStat
		// + getFront ( key:string& ) : RetStat
		// + getBack ( key:string& ) : RetStat
		// + clear ( ): RetStat
		// + isEmpty ( ): bool
		// + dump ( ): void
		// + exercise ( ): static void
		// ----------
		//
		class DoublyLinkedList:public List
		{
		private:
			DoublyLinkedNode *front,*back;
		public:
			DoublyLinkedList()
			{
				cout << "DoublyLinkedList()\n";
				size=0;
				front=NULL;
				back=NULL;
			}
			~DoublyLinkedList()
			{
				cout << "~DoublyLinkedList()\n";
				if(!isEmpty())
				{
					cout << "Clearing Nodes\n";
					clear();
				}
				else
				{
					cout << "Empty List Destroyed\n";
				}

			}
			RetStat getElement(int index,string& key)
			{
				cout << "getElement()\n";
				if((index < 0) || (index >= size))
				{
					return FAIL;
				}
				else
				{
					DoublyLinkedNode * current = front;
					for(int ii = 0; ii < index; ii++)
					{
						current=current->next;
					}
					key = current->key;
					return SUCCESS;
				}
			}
			RetStat setElement(int index,const string& key)
			{
				cout << "setElement()\n";
				if((index < 0) || (index >= size))
				{
					return FAIL;
				}
				else
				{
					DoublyLinkedNode * current = front;
					for(int ii = 0; ii < index; ii++)
					{
						current=current->next;
					}
					current->key=key;
					return SUCCESS;
				}
			}
			RetStat pushBack(const string& key)
			{
				cout << "pushBack()\n";
				DoublyLinkedNode *newNode=new DoublyLinkedNode(key);
				if(isEmpty())
				{
					front = back=newNode;
					size=1;
					return SUCCESS;
				}
				else
				{
					newNode->previous=back;
					back->next=newNode;
					back=newNode;
					size++;
					return SUCCESS;
				}
			}
			RetStat pushFront(const string& key)
			{
				cout << "pushFront()\n";
				DoublyLinkedNode *newNode=new DoublyLinkedNode(key);
				if(isEmpty())
				{
					front = back=newNode;
					size=1;
					return SUCCESS;
				}
				else
				{
					newNode->next=front;
					front->previous=newNode;
					front=newNode;
					size++;
					return SUCCESS;
				}
			}
			RetStat popBack(string& key)
			{
				cout << "popBack()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else
				{
					DoublyLinkedNode *oldNode=back;
					back->previous->next=NULL;
					back=back->previous;
					size--;
					if(size==0)
					{
						front=back=NULL;
					}
					key=oldNode->key;
					delete oldNode;
					return SUCCESS;
				}
			}
			RetStat popFront(string& key)
			{
				cout << "popFront()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else if(front == back)
				{
					key = front->key;
					delete front;
					front=back=NULL;
					size = 0;
					return SUCCESS;
				}
				else
				{
					DoublyLinkedNode *oldNode=front;
					front->next->previous=NULL;
					front=front->next;
					size--;
					if(size==0)
					{
						back=front=NULL;
					}
					key=oldNode->key;
					delete oldNode;
					return SUCCESS;
				}
			}
			RetStat getFront(string& key)
			{
				cout << "getFront()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else
				{
					key=front->key;
					return SUCCESS;
				}
			}
			RetStat getBack(string& key)
			{
				cout << "getBack()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else
				{
					key=back->key;
					return SUCCESS;
				}
			}
			RetStat clear()
			{
				cout << "clear()\n";
				DoublyLinkedNode *oldNode=front;
				while(oldNode!=NULL)
				{
					front=oldNode->next;
					delete oldNode;
					oldNode=front;
				}
				size=0;
				front=back=NULL;
				return SUCCESS;
			}
			bool isEmpty()
			{
				cout << "isEmpty()";
				if (front == NULL)
				{
					cout << "-True\n";
					return true;
				}
				cout << "-False\n";
				return false;
			}
			void dump()
			{
				cout << "dump()\n";
				DoublyLinkedNode *current=front;
				cout <<"FRONT->"<<front<<"\n";
				for(int ii=0; current!=NULL; ii++)
				{
					current=current->next;
					cout << "Node #"<<ii<<"\n";
					cout << "*Previous=";
					if(current->previous==NULL)
					{
						cout <<"NULL";
					}
					else
					{
						cout <<current->previous;
					}
					cout << "\n*Next=";
					if(current->next==NULL)
					{
						cout <<"NULL";
					}
					else
					{
						cout <<current->next;
					}
					cout << "\nKey="<<current->key.c_str();
				}
				cout << "BACK->"<<back<<"\n";
			}

		};

		// SinglyLinkedNode
		// ----------
		// + key:string
		// + next:SinglyLinkedNode*
		// ----------
		// + SinglyLinkedNode ( key:string )
		// + ~SinglyLinkedNode ( )
		// ----------
		class SinglyLinkedNode
		{
		public:
			string key;
			SinglyLinkedNode* next;
			SinglyLinkedNode(string newKey)
			{
				cout << "SinglyLinkedNode() : "<<newKey.c_str()<<"\n";
				key=newKey;
			}
			~SinglyLinkedNode()
			{
				cout << "~SinglyLinkedNode()\n";
			}
		};
		//
		// SinglyLinkedList
		// (derives from List)
		// ----------
		// - front:SinglyLinkedNode*
		// - back:SinglyLinkedNode*
		// ----------
		// + SinglyLinkedList ( )
		// + ~SinglyLinkedList ( )
		// + getElement ( index:int, key:string& ): RetStat
		// + setElement ( index:int, key:const string& ): RetStat
		// + pushBack ( key:const string& ) : RetStat
		// + pushFront ( key:const string& ) : RetStat
		// + popBack ( key:string& ) : RetStat
		// + popFront ( key:string& ) : RetStat
		// + getFront ( key:string& ) : RetStat
		// + getBack ( key:string& ) : RetStat
		// + clear ( ): RetStat
		// + isEmpty ( ): bool
		// + dump ( ): void
		// + exercise ( ): static void
		// ----------
		//
		//
		class SinglyLinkedList:public List
		{
		private:
			SinglyLinkedNode *front,*back;
		public:
			SinglyLinkedList()
			{
				cout << "SinglyLinkedList()\n";
			}
			~SinglyLinkedList()
			{
				cout << "~SinglyLinkedList()\n";
			}
			RetStat getElement(int index,string& key)
			{
				cout << "getElement()\n";
				if((index < 0) || (index >= size))
				{
					return FAIL;
				}
				else
				{
					SinglyLinkedNode * current = front;
					for(int ii = 0; ii < index; ii++)
					{
						current=current->next;
					}
					key = current->key;
					return SUCCESS;
				}
			}
			RetStat setElement(int index,const string& key)
			{
				cout << "setElement()\n";
				if((index < 0) || (index >= size))
				{
					return FAIL;
				}
				else
				{
					SinglyLinkedNode * current = front;
					for(int ii = 0; ii < index; ii++)
					{
						current=current->next;
					}
					current->key=key;
					return SUCCESS;
				}
			}
			RetStat pushBack(const string& key)
			{
				cout << "pushBack()\n";
				SinglyLinkedNode *newNode=new SinglyLinkedNode(key);
				if(isEmpty())
				{
					front=back=newNode;
					size=1;
					return SUCCESS;
				}
				else
				{
					//newNode->previous=back;
					back->next=newNode;
					back=newNode;
					size++;
					return SUCCESS;
				}
			}
			RetStat pushFront(const string& key)
			{
				cout << "pushFront()\n";
				SinglyLinkedNode *newNode=new SinglyLinkedNode(key);
				if(isEmpty())
				{
					front = back=newNode;
					size=1;
					return SUCCESS;
				}
				else
				{
					newNode->next=front;
					//front->previous=newNode;
					front=newNode;
					size++;
					return SUCCESS;
				}
			}
			RetStat popBack(string& key)
			{
				cout << "popBack()\n";
				//TEMP fix?!?!? Neeed HELPPPPPPPP!!!!!!!!!!!!!----------------------------------------------------
				if(back!=NULL){
					front=NULL;
				}
				//------------------------------------------------------------------------------------------------
				if(isEmpty())
				{
					return FAIL;
				}
				else
				{
					SinglyLinkedNode *oldNode=back;
					//loop to find

					size--;
					if(size==0)
					{
						front=back=NULL;
					}
					key=oldNode->key;
					delete oldNode;
					return SUCCESS;
				}

			}
			RetStat popFront(string& key)
			{
				cout << "popFront()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else if(front == back)
				{
					key = front->key;
					delete front;
					front=back=NULL;
					size = 0;
					return SUCCESS;
				}
				else
				{
					SinglyLinkedNode *oldNode=front;
					//front->next->previous=NULL;
					front=front->next;
					size--;
					if(size==0)
					{
						back=front=NULL;
					}
					key=oldNode->key;
					delete oldNode;
					return SUCCESS;
				}
			}
			RetStat getFront(string& key)
			{
				cout << "getFront()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else
				{
					key=front->key;
					return SUCCESS;
				}
			}
			RetStat getBack(string& key)
			{
				cout << "getBack()\n";
				if(isEmpty())
				{
					return FAIL;
				}
				else
				{
					key=back->key;
					return SUCCESS;
				}
			}
			RetStat clear()
			{
				cout << "clear()\n";
				SinglyLinkedNode *oldNode=front;
				while (front != NULL)
				{
					oldNode = front;
					front = front->next;
					delete oldNode;
				}
				size=0;
				front=back=NULL;
				return SUCCESS;
			}
			bool isEmpty()
			{
				cout << "isEmpty()";
				if (front == NULL)
				{
					cout << "-True\n";
					return true;
				}
				cout << "-False\n";
				return false;
			}
			void dump()
			{
				cout << "dump()\n";
				SinglyLinkedNode *current=front;
				cout <<"FRONT->"<<front<<"\n";
				for(int ii=0; current!=NULL; ii++)
				{

					if(current->next==NULL)
					{
						cout <<"NULL";
					}
					else
					{
						cout <<current->next;
						current=current->next;
						cout << "Node #"<<ii<<"\n";
						cout << "\n*Next=";
					}
					cout << "\nKey="<<current->key.c_str();
				}
				cout << "BACK->"<<back<<"\n";
			}

		};

	}
}
#endif
