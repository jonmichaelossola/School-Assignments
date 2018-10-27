/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Ercanbrack, CS 235
 * Author:
 *    Br. Helfrich
 *    Modified by Scott Ercanbrack - removed most of the the BST class functions,
 *                                   but left BST Iterator class.
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"    // for BinaryNode
#include "stack.h"    // for Stack

// forward declaration for the BST iterator
template <class T>
class BSTIterator; 

/*****************************************************************
 * BINARY SEARCH TREE
 * Create a Binary Search Tree
 *****************************************************************/
template <class T>
class BST
{
public:
   // constructor
   BST(): root(NULL){};
   
   // copy constructor
   BST(const BST & rhs) throw (const char *);    
   
   ~BST();

   // BinaryNode class needs a size function
   int  size() const  { return empty() ? 0 : root->size(); }   
   
   // determine if the tree is empty
   bool empty() const
   {
      if (root == NULL) 
         return true;
      else 
         return false;
   }

   // remove all the nodes from the tree.  Makes an empty tree.
   void clear()
   {
      if (root == NULL)
         return;
      else
      {
         deleteBinaryTree(root);
         root = NULL;
      }
   }

   // overloaded assignment operator
   BST & operator = (const BST & rhs) throw (const char *)
   {
      if (this->root != NULL)
         deleteBinaryTree(this->root);

      if (rhs.root == NULL)
         return *this;

      try 
      {
         this->root = new BinaryNode<T>(rhs.root->data);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Bad allocation errors";
      }

      if (rhs.root->pLeft)
         this->insertSubtree(rhs.root->pLeft);
      if (rhs.root->pRight)
         this->insertSubtree(rhs.root->pRight);

      return *this;
   }
      
   // insert an item
   void insert(const T & t) throw (const char * );

   // remove an item
   void remove(BSTIterator <T> & it);

   // find a given item
   BSTIterator <T> find(const T & t);

   // the usual iterator stuff
   BSTIterator <T> begin() const;
   BSTIterator <T> end() const  { return BSTIterator <T> (NULL) ; }
   BSTIterator <T> rbegin() const;
   BSTIterator <T> rend() const  { return BSTIterator <T> (NULL); }
   
private:

   BinaryNode <T> * root;
   // some private functions I made for better modularization
   void insertSubtree(BinaryNode <T> * p);
   void removeParent(BinaryNode <T> * p);
   void removeLeaf(BinaryNode <T> * p);
};

/*********************************************************
* copy constructor
**********************************************************/
template <class T>
BST<T>::BST(const BST &rhs) throw (const char *)
{
   if (rhs.root == NULL)
   {
      this->root = NULL;
      return;
   }

   // copy the root first, don't want a linear search.
   try 
   {
      this->root = new BinaryNode<T>(rhs.root->data);
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Bad allocation errors";
   }
   
   // copy the subtrees! :D 
   if (rhs.root->pLeft)
      this->insertSubtree(rhs.root->pLeft);
   if (rhs.root->pRight)
      this->insertSubtree(rhs.root->pRight);

}

/*****************************************************
* Made this private function so that I could insert
* into my main tree.
*****************************************************/
template <class T>
void BST <T> :: insertSubtree(BinaryNode <T> * p)
{
   insert(p->data);
   
   if (p->pLeft)
   {
      insertSubtree(p->pLeft);
   }

   if (p->pRight)
   {
      insertSubtree(p->pRight);
   }

}

/*****************************************************
* Destructor
*******************************************************/
template <class T>
BST<T>::~BST()
{
   deleteBinaryTree(root);
}


/*****************************************************
 * BST :: BEGIN
 * Return the first node (left-most) in a binary search tree
 ****************************************************/
template <class T>
BSTIterator <T> BST <T> :: begin() const
{
   Stack < BinaryNode <T> * > nodes;

   nodes.push(NULL);
   nodes.push(root);
   while (nodes.top() != NULL && nodes.top()->pLeft)
      nodes.push(nodes.top()->pLeft);

   return BSTIterator<T>(nodes);   
}

/*****************************************************
 * BST :: RBEGIN
 * Return the last node (right-most) in a binary search tree
 ****************************************************/
template <class T>
BSTIterator <T> BST <T> :: rbegin() const
{
   Stack < BinaryNode <T> * > nodes;

   nodes.push(NULL);
   nodes.push(root);
   while (nodes.top() != NULL && nodes.top()->pRight)
      nodes.push(nodes.top()->pRight);

   return BSTIterator<T>(nodes);
}  

/*****************************************************
 * BST :: INSERT
 * Insert a node at a given location in the tree
 ****************************************************/
template <class T>
void BST <T> :: insert(const T & t) throw (const char *)
{
   // we need to find the leaf node.
   BinaryNode <T> * p = root;

   if (root == NULL)
   {
      BinaryNode <T> * newNode = new BinaryNode <T>(t);
      root = newNode;
   }
   else
   {
      while (p)
      {
         if (t >= p->data && !p->pRight)
         {
            p->addRight(t);
            break;
         }
         if (t <= p->data && !p->pLeft)
         {
            p->addLeft(t);
            break;
         }
         if (t > p->data && p->pRight)
         {
            p = p->pRight;
         }
         else if (t < p->data && p->pLeft)
         {
            p = p->pLeft;
         }
      }
   }

}

/*************************************************
* This will get called from our original remove
* function. It removes a leaf of our tree.
*************************************************/
template <class T>
void BST <T> :: removeLeaf(BinaryNode <T> * p)
{
   //std::cerr << "We are removing the " << p->data << " node\n";
   if (p->data > p->pParent->data)
      p->pParent->pRight = NULL;
   else
      p->pParent->pLeft = NULL;

   delete p;
}

/************************************************
* This will also get called from our remove function.
* remove a node that has one child.
*************************************************/
template <class T>
void BST <T> :: removeParent(BinaryNode <T> * p)
{
   // case of only one child.
   // child is at pRight pointer
   if (p->pRight)
   {
         p->pRight->pParent = p->pParent;
      // p is the right child of the its parent, else,
      // it is the left child of parent.
      if (p->data > p->pParent->data)
         p->pParent->pRight = p->pRight;
      else
         p->pParent->pLeft = p->pRight;
      delete p;
   }
   else if (p->pLeft)
   {
      p->pLeft->pParent = p->pParent;

      if (p->data > p->pParent->data)
         p->pParent->pRight = p->pLeft;
      else
         p->pParent->pLeft = p->pLeft;
      delete p;
   }
}

/*************************************************
 * BST :: REMOVE
 * Remove a given node as specified by the iterator
 ************************************************/
template <class T>
void BST <T> :: remove(BSTIterator <T> & it)
{
   // let's make a pointer to the current node.
   BinaryNode <T> * p = it.getNode();

   // we have four cases. Start with leaf node.
   if (!p->pRight && !p->pLeft)
      removeLeaf(p);
   else if (p->pRight && p->pLeft)
   {
      // this is case that node deleted has two kids
      BinaryNode <T> * successor = it.getNode();

      // find the succeeding node
      successor = successor->pRight;
      while (successor->pLeft)
         successor = successor->pLeft;
      
      p->data = successor->data;

      if (!successor->pRight && !successor->pLeft)
         removeLeaf(successor);
      else
         removeParent(successor);

   }
   else
      removeParent(p);
}

/****************************************************
 * BST :: FIND
 * Return the node corresponding to a given value
 ****************************************************/
template <class T>
BSTIterator <T> BST <T> :: find(const T & t)
{
   BinaryNode <T> * pNode = root;
   bool found = false;

   while (pNode)
   {
      if (pNode && t == pNode->data)
      {
         found = true;
         break;
      }
      if (t > pNode->data)
         pNode = pNode->pRight;
      else if (t < pNode->data)
         pNode = pNode->pLeft;
   }
   if (!found)
      return end();
   else
   {
      BSTIterator <T> p(pNode);
      return p;
   }
}


/**********************************************************
 * BINARY SEARCH TREE ITERATOR
 * Forward and reverse iterator through a BST
 *********************************************************/
template <class T>
class BSTIterator
{
public:
   // constructors
   BSTIterator(BinaryNode <T> * p = NULL)    { nodes.push(p);  }
   BSTIterator(Stack <BinaryNode <T> *> & s) { nodes = s;         }
   BSTIterator(const BSTIterator <T> & rhs)  { nodes = rhs.nodes; }

   // assignment
   BSTIterator <T> & operator = (const BSTIterator <T> & rhs)
   {
      // need an assignment operator for the Stack class.
      nodes = rhs.nodes;
      return *this;
   }

   // compare
   bool operator == (const BSTIterator <T> & rhs) const
   {
      // only need to compare the leaf node 
      return rhs.nodes.const_top() == nodes.const_top();
   }
   bool operator != (const BSTIterator <T> & rhs) const
   {
      // only need to compare the leaf node 
      return rhs.nodes.const_top() != nodes.const_top();
   }

   // de-reference. Cannot change because it will invalidate the BST
   T & operator * ()  
   {
      return nodes.top()->data;
   }

   // iterators
   BSTIterator <T> & operator ++ ();
   BSTIterator <T>   operator ++ (int postfix)
   {
      BSTIterator <T> itReturn = *this;
      ++(*this);
      return itReturn;
   }
   BSTIterator <T> & operator -- ();
   BSTIterator <T>   operator -- (int postfix)
   {
      BSTIterator <T> itReturn = *this;
      --(*this);
      return itReturn;
   }

   // must give friend status to remove so it can call getNode() from it
   friend void BST <T> :: remove(BSTIterator <T> & it);

private:
   
   // get the node pointer
   BinaryNode <T> * getNode() { return nodes.top(); }
   
   // the stack of nodes
   Stack < BinaryNode <T> * > nodes;
};


/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 * advance by one
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator ++ ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;
   
   // if there is a right node, take it
   if (nodes.top()->pRight != NULL)
   {
      nodes.push(nodes.top()->pRight);

      // there might be more left-most children
      while (nodes.top()->pLeft)
         nodes.push(nodes.top()->pLeft);
      return *this;
   }

   // there are no right children, the left are done
   assert(nodes.top()->pRight == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the left-child, got to the parent.
   if (pSave == nodes.top()->pLeft)
      return *this;

   // we are the right-child, go up as long as we are the right child!
   while (nodes.top() != NULL && pSave == nodes.top()->pRight)
   {
      pSave = nodes.top();
      nodes.pop();
   }
      
   return *this;      
}

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 * advance by one
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator -- ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a left node, take it
   if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

      // there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(nodes.top()->pLeft == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}


#endif // BST_H
