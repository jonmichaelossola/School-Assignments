/***********************************************************************
 * Header:
 *    Node
 * Summary:
 *    This class contains the notion of a Node: a bucket to hold
 *    data for the user. This is just a starting-point for more advanced
 *    constainers such as the Node, Node, stack, queue, deque, and map
 *    which we will build later this semester.
 *
 *    This will contain the class definition of:
 *        Node         : A class that links lists
 * Author
 *    Austin Nelson
 ************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>       // for CIN and COUT

/***********************************************************************
 * Name: node (class)
 * Data Type: node
 * Purpose: to hold things
 ************************************************************************/
template <class T>
class Node
{
public:
    T data;
    Node<T> * pNext;
    Node<T> * pPrev;
    // default constructor : empty and kinda useless
    Node() : pNext(NULL), pPrev(NULL), data(T()) {}
    
    // non-default constructor : pre-allocate
    Node(const T object) throw (const char *);
};

/***********************************************************************
 * Name: node (non-default constructor)
 * Data Type: node
 * Parameters: capacity
 * Return: nothing
 * Purpose: preallocate the node
 ************************************************************************/
template <class T>
Node<T> :: Node(const T object) throw (const char *)
{
    this->data = object;
    this->pNext = NULL;
    this->pPrev = NULL;
}

/***********************************************************************
 * Name: copy
 * Data Type: Template
 * Parameters: pointer to node
 * Return: the new linked list
 * Purpose: copy the linked list
 ************************************************************************/
template <class T>
Node<T> * copy(Node<T> * & pHead) throw (const char *)
{
    // make sure that you're not done, then call this recursively until done
    if (pHead == NULL)
    {
        return pHead;
    }
    
    // create the new node
    Node<T> * newNode;
    try
    {
        // try initializing it and copying the thing
        newNode = new Node<T>(pHead->data);
    }
    catch(std::bad_alloc)
    {
        throw "Not enough memory";
    }
    
    // make sure you handle the previous node
    newNode->pPrev = pHead;
    
    // go recursive
    newNode->pNext = copy(pHead->pNext);
    
    // end
    return newNode;
}

/***********************************************************************
 * Name: insert
 * Data Type: void
 * Parameters: template object, pHead node pointer, and sometimes a boolean front
 * Return: none
 * Purpose: put a new node into the current list
 ************************************************************************/
template <class T>
void insert(const T & object, Node<T> * & afterMe, bool front = false) throw (const char *)
{
    // make the new node to be inserted
    Node<T> * newNode;
    
    // try allocating
    try
    {
        newNode = new Node<T>(object);
    }
    catch (std::bad_alloc)
    {
        throw "Not enough space";
    }
    
    // assuming there isn't a exception thrown, check for NULL
    if (afterMe == NULL)
    {
        afterMe = newNode;
        return;
    }
    
    // if front is true
    if (front)
    {
        newNode->pNext = afterMe;
        afterMe = newNode;
    }
    
    // all other things
    else
    {
        newNode->pNext = afterMe->pNext;
        afterMe->pNext = newNode;
    }
}

/***********************************************************************
 * Name: find
 * Data Type: Node Template
 * Parameters: pHead and the object to be found
 * Return: the find function itself.
 * Purpose: find the node corresponding to a given passed value from a list
 ************************************************************************/
template <class T>
Node<T> * find(Node<T> * pHead, T object) throw (const char *)
{
    if (pHead == NULL || pHead->data == object)
    {
        // if nothing is there or if it is found
        return pHead;
    }
    else
    {
        // return recursivley
        return find(pHead->pNext, object);
    }
}


/***********************************************************************
 * Name: operator <<
 * Data Type: Template
 * Parameters: out, and pHead, or the beginning
 * Return: out
 * Purpose: to display the linked list
 ************************************************************************/
template <class T>
std::ostream & operator << (std::ostream & out, const Node<T> * pHead)
{
    
    if (pHead == NULL)
    {
        return out;
    }
    else
    {
        if (pHead->pNext != NULL)
        {
            out << pHead->data << "  ";
            out << pHead->pNext;
        }
        else
            out << pHead->data;
    }
    return out;
}

/***********************************************************************
 * Name: freeData
 * Data Type: void
 * Parameters: pHead
 * Return: none
 * Purpose: to delete all the data
 ************************************************************************/
template <class T>
void freeData(Node<T> * & pHead)
{
    if (pHead == NULL)
    {
        return;
    }
    else
    {
        freeData(pHead->pNext);
        delete pHead;
        pHead = NULL;
    }
    return;
}

#endif // NODE_H
