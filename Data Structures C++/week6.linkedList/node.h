#ifndef NODE_H
#define NODE_H

/********************************************************************
* This is the Node class. We have constructors, and then we have
* our variables, a pointer to the next node object, and data to 
* store our data in.
*********************************************************************/
template <class T>
class Node
{
public:
	Node() : data(T()), pNext(NULL) {}
	Node(const T &newData) : data(newData), pNext(NULL) {}
	Node<T> * pNext;
	T data;
};

/*******************************************************************
* Copy function. Let's do this recursively: it's a lot more simpler
* this way. We will create a new node and put the data into it, and
* then we will call this function again and again until we get null.
*******************************************************************/
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

/*******************************************************************
* Insert function. We need to have a few checks to make sure that
* we can do the operation we want, like checking if what we are 
* inserting is the first item in the list. 
*******************************************************************/
template <class T>
inline void insert(const T &newData, Node<T> *& precedingNode, bool listHead = false)
{
	Node <T> * p = new Node <T>;

	// set the data equal to the parameter passed in.
	p->data = newData;

	// if listHead is true, we are putting this at the top of the linked list.
	if (listHead)
	{
		// we make the former starting node the next node in the sequence
		p->pNext = precedingNode;

		// Have the pointer point to our head node.
		precedingNode = p;
	}
	else 
	{
		// if preceding node is null, set the pnext of our current node to null.
		// else, set the pNext of our node to what the preceding node's pNext was.
		if (precedingNode == NULL)
			p->pNext = NULL;
		else
			p->pNext = precedingNode->pNext;

		// Now make the preceding node point to our new node.
		if (precedingNode != NULL)
			precedingNode->pNext = p;
		else if (precedingNode == NULL)
			precedingNode = p;
	}
}

/*******************************************************************
* Find function. Loop through the Nodes, checking with if the data
* in p is equal to the value we are searching for. If it is, we are
* simply going to return p. If it's not in the nodes, return null.
*******************************************************************/
template <class T>
inline Node<T>* find(Node<T> * pHead, const T &findThis)
{
	for (Node <T> * p = pHead; p != NULL; p = p->pNext)
	{
		if (p->data == findThis)
		{
			return p;
		}
	}

	return NULL;
}

/*******************************************************************
* Overided operator for the angle brackets, to ouptut something.
* Loop through each node, and output each with a comma and a space
* after until the last node, where we will just output the data.
*******************************************************************/
template <class T>
inline std::ostream & operator << (std::ostream & out, Node<T> * pHead)
{
	for (Node <T> * p = pHead; p; p = p->pNext)
	{
		if (p->pNext != NULL)
		{
			out << p->data << ", ";
		}
		else
		{
			out << p->data; 
			break;
		}
	}

	return out;
}

/*******************************************************************
* Free data function. Declare two Node pointers, and loop through
* the array, deleting each item. After freeing the memory for all 
* the nodes, make the pHead null and that's a wrap!
*******************************************************************/
template <class T>
inline void freeData(Node<T> *& pHead)
{
	Node <T> * p = pHead;
	Node <T> * next;

	while (p)
	{
		next = p->pNext;
		delete p;
		p = next;
	}

	pHead = NULL;
}

#endif // NODE_H