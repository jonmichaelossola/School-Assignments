#ifndef BNODE_H
#define BNODE_H

#include <iostream> 
#include <cassert>

/*****************************************************************
 * BINARY NODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BinaryNode
{
public:
	// constructors! Set everything to NULL/default value except for second constructor
	BinaryNode() : data(T()), pLeft(NULL), pRight(NULL), pParent(NULL) {}
	BinaryNode(const T &newData) : data(newData), pLeft(NULL), pRight(NULL), pParent(NULL) {}

   // return size (i.e. number of nodes in tree)
   int size() const
   {
            return 1 +
               (pLeft== NULL? 0 : pLeft->size()) +
               (pRight == NULL ? 0 : pRight->size());
   }
   
   // add a node to the left/right
   void addLeft (BinaryNode <T> * pNode);
   void addRight(BinaryNode <T> * pNode);

   // create a node and add it to the left/right
   void addLeft (const T & t) throw (const char *);
   void addRight(const T & t) throw (const char *);
   
   // since no validation is done, everything is public
   BinaryNode <T> * pLeft;
   BinaryNode <T> * pRight;
   BinaryNode <T> * pParent;
   T data;
};

/****************************************************************
* Simple enough. The this parameter will be the parent of the node
* passed in. change the parent pointer of the passed in node to 
* point to this, and have the left pointer of this point to pNode.
*****************************************************************/
template <class T>
void BinaryNode <T> :: addLeft(BinaryNode <T> * pNode)
{
	if (pNode != NULL)
	   pNode->pParent = this;

	this->pLeft = pNode;
}

/*****************************************************************
* Create a new node, use non default constructor to allocate a 
* new node with value. Then set the pParent pointer to this, and
* connect the left pointer of this to the new node.
*****************************************************************/
template <class T>
void BinaryNode <T> :: addLeft(const T & t) throw (const char *)
{
	BinaryNode <T> * p;

	try
	{
		p = new BinaryNode <T>(t);	
	}
	catch (std::bad_alloc)
	{
		throw "ERROR: Unable to allocate a new node";
	}

	p->pParent = this;
	this->pLeft = p;
}

/*****************************************************************
* Add right function. Add a node to the right side of this, by
* connecting the passed in nodes to the this pointer as well as 
* setting the pRight node of this to the node passed in.
*****************************************************************/
template <class T>
void BinaryNode <T> :: addRight(BinaryNode <T> * pNode)
{
	if (pNode != NULL)
	   pNode->pParent = this;

	this->pRight = pNode;
}

/*****************************************************************
* Add to the right side of the Binary tree by creating a new node,
* then calling the non-default constructor for the data. It then
* allocates a new node, and makes connections between the nodes.
*****************************************************************/
template <class T>
void BinaryNode <T> :: addRight(const T & t) throw (const char *)
{
	BinaryNode <T> * p;

	try
	{
		p = new BinaryNode <T>(t);
	}
	catch (std::bad_alloc)
	{
		throw "ERROR: Unable to allocate a node";
	}

	p->pParent = this;
	this->pRight = p;
}

/*****************************************************************
* Delete function. Recursively start at the leaves of the tree,
* delete them, set each pointer to NULL, then set the first of 
* the nodes to NULL. 
*****************************************************************/
template <class T>
void deleteBinaryTree(BinaryNode <T> *& pNode)
{
	BinaryNode <T> * p = pNode;

	// Recursive part of the function
	if (p != NULL)
	{
		// Go to the left most node
		if (p->pLeft) 
			deleteBinaryTree(p->pLeft);

		// check to see if there are nodes to right
		if (p->pRight)
			deleteBinaryTree(p->pRight);

		// after reaching the end node of tree, delete it.
		delete p;
		p = NULL;
	}

	// anchor case, return if p is NULL
	if (p == NULL)
		return;

	pNode = NULL;
}

/*****************************************************************
* Insertion operator. This is also going to be recursive. Create
* a pointer to pNode, then traverse tree by going to left most node,
* print out data, then go to the right most node (LVR).
*****************************************************************/
template <class T>
std::ostream & operator << (std::ostream & out, BinaryNode <T> * pNode)
{
	// create a temporary pointer to traverse the nodes
	BinaryNode <T> * p = pNode;

	if (p != NULL)
	{
		// Visit the left most node first
		if (p->pLeft)
			out << p->pLeft;

		// Visit and display data in node
		out << p->data << ' ';

		// Visit now the node on the right
		if (p->pRight)
			out << p->pRight;
	}
	if (p == NULL)
		return out;

	return out;
}

#endif // BNODE_H
