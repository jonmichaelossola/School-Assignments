#ifndef BNODE_H
#define BNODE_H

#include <iostream> 
#include <cassert>
#include <iostream>

/*****************************************************************
 * BINARY NODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BinaryNode
{
public:
	void level();

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

/**********************************************************************
 * Display person function. This will display every single person
 * according to their needs.
 ***********************************************************************/
void displayGeneration(const int &numGen)
{
	if (numGen == 1)
		std::cout << "Parents:\n";
	else if (numGen == 2)
		std::cout << "Grandparents:\n";
	else if (numGen == 3)
		std::cout << "Great Grandparents:\n";
	else if (numGen == 4)
		std::cout << "2nd Great Grandparents:\n";
	else if (numGen == 5)
		std::cout << "3rd Great Grandparents:\n";
	else if (numGen == 6)
		std::cout << "4th Great Grandparents:\n";
	else if (numGen == 7)
		std::cout << "5th Great Grandparents:\n";
}

/****************************************************************
* This is our level function: It is basically the display function
* for our binary tree and works 
* 
*****************************************************************/
template <class T>
void BinaryNode <T> :: level()
{
  const int MAX = 100;
  BinaryNode *queue[MAX];
  BinaryNode *temp;
  int front = 0;
  int back = 0;
  int savedBack = 1;
  int numGenerations = 0;

  queue[back++] = this;

  // displayGeneration(numGenerations++, this->data);
  std::cout << "The Ancestors of ";
  displayFirst(this->data);
  numGenerations++;

  while (front != back)
  {
    temp = queue[front];
    front = (front + 1) % MAX;

    // if (temp->data.lastName == "Zimdars")
    // 	std::cout << "We definitely visit him in the nodes!\n";
    if (temp != NULL)
    {
       // visit
        if (temp->data.id != 1)
          {
          std::cout << "        ";
          display(temp->data);    
       }
       // end Visit        
      queue[back] = temp->pLeft;
      back = (back + 1) % MAX;
      queue[back] = temp->pRight;
      back = (back + 1) % MAX;
    }
   	if (front == savedBack)
   	{
   		displayGeneration(numGenerations);
   		savedBack = back;
   		numGenerations++;
   	}
  }
}

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
