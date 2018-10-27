#ifndef NODE_H
#define NODE_H

/********************************************************************
* This is the Node class. We have constructors, and then we have
* our variables, a pointer to the next node object, and data to 
* store our data in. I took out any unnecessary, unused functions.
*********************************************************************/
template <class T>
class Node
{
public:
	Node() : data(T()), pNext(NULL), pPrevious(NULL) {}
	Node(const T &newData) : data(newData), pNext(NULL), pPrevious(NULL) {}
	Node<T> * pNext;
	Node<T> * pPrevious;
	T data;
};

/******************************************************************
* Copy function. Let's do this recursively: it's a lot more simpler
* this way. We will create a new node and put the data into it, and
* then we will call this function again and again until we get null.
******************************************************************/
template <class T>
inline Node<T>* copy(const Node<T> * pHead)
{
	// this is our anchor case if pHead is Null, then return NULL
	if (pHead == NULL)
	{
		return NULL;
	}

	// Let's use a recursive function to make a new linked list.
	Node <T> * temp = new Node <T> (pHead->data);
	temp->pNext = copy(pHead->pNext);

	return temp;
}


#endif // NODE_H