/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Jon Michael Ossola
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include "huffman.h"       // for HUFFMAN() prototype

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

typedef Pair<string, float> HuffPair;
typedef BinaryNode<Pair <string, float> > BinHuffPair;
typedef list<BinaryNode <Pair <string, float> >* > HuffList;
typedef BinaryNode<Pair <string, float> >* pHuffPair;

/**********************************************************************
* We need this for the list's sort function. This compares two binary
* node pointers to pairs which contain stringacters and floats.
**********************************************************************/
bool compare(BinHuffPair * one, BinHuffPair * two)
{
	return (one->data.second < two->data.second);
}

/********************************************************************
* Display the list. The huffman code is contained inside the first
* pair parameter. We are going to split it up and display.
*********************************************************************/
void display(HuffList &theList)
{
	for (HuffList::iterator it = theList.begin(); it != theList.end(); it++)
	{
		for (int i = 0; i < (*it)->data.first.size(); i++)
		{
			if (i == 0)
			   cout << (*it)->data.first[i] << " = ";
			else
			{
				cout << (*it)->data.first[i];
			}
		}
		cout << endl;
	}
}

/*********************************************************************
* Traverse the array, and when we hit a leaf, we need to calculate 
* what the huffman code was recursively, then add that to the string.
**********************************************************************/
void traverse(pHuffPair root, string code, HuffList &theList)
{
	// if it's a leaf node, add that to the original string.
	if (root->pLeft == NULL && root->pRight == NULL)
	{
		for (HuffList::iterator it = theList.begin(); it != theList.end(); it++)
		{
			string i;
			if (root->data.first == (*it)->data.first)
			{
				i = (*it)->data.first;
				i += code;
				(*it)->data.first = i;
			}
		}
		return;
	}
	else 
	{
		traverse(root->pLeft, code + '0', theList);
		traverse(root->pRight, code + '1', theList);
	}
}


// This was my first attempt. I think this works, just in a different way
/*********************************************************************
* This was my first attempt, works recursively, it's just a little
* more complicated than the method below.
**********************************************************************/
// string findCode(pHuffPair root, string myChar, string &addOn, bool &found)
// {
// 	found = false;

// 	if (root->data.first == myChar)
// 	{
// 		found = true;
// 		return addOn;
// 	}

// 	if (root->pLeft)
// 	{
// 		// if the node has a left, recursively call this again.
// 		if (found)
// 		   addOn += findCode(root->pLeft, myChar, addOn, found);
// 		else
// 			findCode(root->pLeft, myChar, addOn, found);
// 		// Add a 0 onto the string
// 		if (found)
// 		   addOn += '0';
// 	}

// 	if (found)
// 	{
// 		return addOn;
// 	}

// 	if (root->pRight)
// 	{
// 		// if the node has a right node, call this again.
// 		if (found)
// 		   addOn += findCode(root->pRight, myChar, addOn, found);
// 		else
// 			findCode(root->pRight, myChar, addOn, found);
// 		// add a one onto the string
// 		if (found)
// 		   addOn += '1';
// 	}

// 	return addOn;
// }

/**********************************************************************
* Iterate through the list and create a tree. To do this, we are going
* to make trees on trees and then eventually connect them.
***********************************************************************/
pHuffPair buildTree(HuffList &tree)
{
	while (tree.size() > 1)
	{
		// declare a new temporary node
		pHuffPair tmp = new BinHuffPair;

		// get the front value of tree
		tmp->pLeft = tree.front();

		// make probability of second of tmp = to front item of tree
		tmp->data.second = tree.front()->data.second;

		// make tmp the parent of tree's front
		tree.front()->pParent = tmp;

		// pop the front item
		tree.pop_front();

		// set the right pointer of tmp to front of tree.
		tmp->pRight = tree.front();

		// add on the second part of data from tree.
		tmp->data.second += tree.front()->data.second;

		// make the front item equal to the temporary node.
		tree.front()->pParent = tmp;

		// pop the second item off of the tree.
		tree.pop_front();

		// push our temporary back onto the list.
		tree.push_back(tmp);

		// sort the tree
		tree.sort(compare);
	}

	// We are going to return the root of the tree.
	pHuffPair root = tree.front();
	return root;
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(string fileName)
{
	Pair<string, float> readData;
	HuffList nodes;

	ifstream fin(fileName.c_str());

	if (fin.fail())
	{
		cout << "Couldn't open the file: " << fileName << endl;
		return;
	}

	while (fin >> readData)
	{
		pHuffPair storeThis = new BinHuffPair(readData);
		nodes.push_back(storeThis);
	}

	HuffList newList = nodes;

	// close the file!! :D
	fin.close();

	// Sort our list, make this funner.
	nodes.sort(compare);

	pHuffPair root = buildTree(nodes);

	pHuffPair newRoot = root;

	string code;
	traverse(root, code, newList);

	display(newList);

   return;
}
