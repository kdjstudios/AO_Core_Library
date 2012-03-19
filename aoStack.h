/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOSTACK_H
#define AOSTACK_H
#include <cassert>
namespace ao
{
namespace core
{
//
// StackAbstract
// (struct template)
// ----------
// + initializeStack():void
// + isEmptyStack():bool
// + isFullStack(); bool
// + push(TYPE): void
// + top(): TYPE
// + pop(): void
// ----------
//
template <class TYPE>struct StackAbstract
{
    virtual void initializeStack()=0;
    virtual bool isEmptyStack()const =0;
    virtual bool isFullStack()const =0;
    virtual void push(const TYPE &newItem)=0;
    virtual TYPE top()const=0;
    virtual void pop()=0;
};
//
// Stack
// (class template)
// ----------
// + initializeStack():void
// + isEmptyStack():bool
// + isFullStack(); bool
// + push(TYPE): void
// + top(): TYPE
// + pop(): void
// ----------
// + Stack(int newSize=10)
// + Stack(const Stack& other)
// + ~Stack()
// ----------
// - m_MaxSize: int
// - m_Top: int
// - m_List: TYPE*
// - copy(const Stack& other): void
//
template <class TYPE> class Stack:public StackAbstract<TYPE>
{
public:
    void initializeStack()
    {
        m_Top=0;
    }
    bool isEmptyStack()const
    {
        return (m_Top==0);
    }
    bool isFullStack()const
    {
        return (m_Top==m_MaxSize);
    }
    void push(const TYPE &newItem)
    {
        if (!isFullStack())
        {
            m_List[m_Top]=newItem;
            m_Top++;
        }
        //else //maybe put this into try and catch
    }
    TYPE top()const
    {
        assert(m_Top!= 0);
        return m_List[m_Top-1];
    }
    void pop()
    {
        if(!isEmptyStack())
            m_Top--;
    }
    Stack(int newSize)
    {
        if(newSize<1)
            newSize=1;
        m_MaxSize=newSize;
        m_Top=0;
        m_List=new TYPE[m_MaxSize];
    }
    ~Stack()
    {
        delete [] m_List;
    }
    Stack(const Stack<TYPE>& other)
    {
        if(this!=other)
            copy(other);
    }
    const Stack<TYPE> operator=(const Stack<TYPE>& other)
    {
        if(this!=other)
            copy(other);
        return *this;
    }
private:
    int m_MaxSize;
    int m_Top;
    TYPE * m_List;
    void copy(const Stack<TYPE>& other)
    {
        delete [] m_List;
        m_MaxSize=other.m_MaxSize;
        m_Top=other.m_Top;
        m_List= new TYPE[m_MaxSize];
        for(int j =0; j<m_Top; j++)
            m_List[j]=other.m_List[j];
    }

};
//
// LinkedNode
// (struct template)
// ----------
// + key:TYPE
// + LinkedNode*: link
// + LinkedNode(TYPE newKey)
// + ~LinkedNode()
// ----------
//
template <class TYPE>struct LinkedNode
{
    TYPE key;
    LinkedNode* link;
    LinkedNode(TYPE newKey)
    {
        ////cout << "SinglyLinkedNode() : "<<newKey.c_str()<<"\n";
        key=newKey;
    }
    ~LinkedNode()
    {
        ////cout << "~SinglyLinkedNode()\n";
        delete [] link;
    }
};
//
// LinkedStack
// (struct template)
// ----------
// + initializeStack():void
// + isEmptyStack():bool
// + isFullStack(): bool
// + push(TYPE & newItem): void
// + top(): TYPE
// + pop(): void
// ----------
// + LinkedStack(int newSize=10)
// + LinkedStack(const Stack& other)
// + ~LinkedStack()
// ----------
//
template <class TYPE>class LinkedStack:public Stack<TYPE>
{
public:
    void initializeStack()
    {
        LinkedNode<TYPE> * temp;
        while (m_Top!=NULL)
        {
            temp=m_Top;
            m_Top=m_Top->link;
            delete temp;
        }
    }
    bool isEmptyStack()const
    {
        return (m_Top==NULL);
    }
    bool isFullStack()const
    {
        return false;    //Thinking Logically
    }
    void push(const TYPE &newItem)
    {
        LinkedNode<TYPE> * newNode;
        newNode=new LinkedNode<TYPE>;
        newNode->key=newItem;
        newNode->link=m_Top;
        m_Top=newNode;
    }
    TYPE top()const
    {
        assert(m_Top!= NULL);
        return m_Top->key;
    }
    void pop()
    {
        LinkedNode<TYPE> * newNode;
        if(m_Top!=NULL)
        {
            newNode=m_Top;
            m_Top=m_Top->link;
            delete newNode;
        }

    }
    LinkedStack()
    {
        m_Top=NULL;
    }
    LinkedStack(int newSize)
    {
        if(newSize<1)
            newSize=1;
        //m_MaxSize=newSize;
        m_Top=0;
        //m_List=new TYPE[m_MaxSize];
    }
    ~LinkedStack()
    {
        delete [] m_Top;
    }
    LinkedStack(const LinkedStack<TYPE>& other)
    {
        if(this!=other)
            copy(other);
    }
    const LinkedStack<TYPE> operator=(const LinkedStack<TYPE>& other)
    {
        if(this!=other)
            copy(other);
        return *this;
    }
private:
    LinkedNode<TYPE> * m_Top;
    void copy(const LinkedStack<TYPE>& other)
    {

        LinkedNode<TYPE> * newNode,*current,*last;
        if(m_Top!=NULL)
            initializeStack();
        if (other.m_Top==NULL)
            m_Top=NULL;
        else
        {
            current=other.m_Top;
            m_Top=new LinkedNode<TYPE>;
            //newNode=m_Top;
            m_Top->key=current->key;
            m_Top->link=current->link;
            last=m_Top;
            current=current->link;
            while (current!=NULL)
            {
                newNode=new LinkedNode<TYPE>;
                newNode->key=current->key;
                newNode->link=NULL;
                last->link=newNode;
                last=newNode;
                current=current->link;
            }
        }
    }
};
}
}
#endif
