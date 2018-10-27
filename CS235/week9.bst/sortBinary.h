/***********************************************************************
 * Module:
 *    Week 09, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
	// Literally the easiest application I've EVER done.
	BST <T> myTree;

	// copy the items into our binary search tree
	for (int i = 0; i < num; i++)
	{
		myTree.insert(array[i]);
	}

	BSTIterator <T> myIter = myTree.begin();

	// copy the items back into the array.
	for (int i = 0; myIter != myTree.end(); i++, myIter++)
	{
		array[i] = *myIter;
	}
}


#endif // SORT_BINARY_H
