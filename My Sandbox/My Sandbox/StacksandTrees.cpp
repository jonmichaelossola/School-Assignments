//
//  StacksandTrees.cpp
//  My Sandbox
//
//  Created by Jon Michael Ossola on 8/8/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include "bst.h"

using namespace std;

/**********************************************************************
 * Problem : Implement a function to check if a binary tree is balanced.
 * For the purposes of this question, a balanced tree is defined such
 * that the heights of the two subtrees of any node never differ by
 * more than one.
 ***********************************************************************/
// recursively gets the balance of a subtree.
void getHeight(BinaryNode<int> * ptr, int & maxScore, int currentScore)
{
    if (!ptr)
    {
        maxScore = 0;
        return;
    }
    
    if (!ptr->pLeft && !ptr->pRight)
    {
        if (maxScore < currentScore)
            maxScore = currentScore;
    }
    
    if (ptr->pLeft)
        getHeight(ptr->pLeft, maxScore, currentScore+1);
    if (ptr->pRight)
        getHeight(ptr->pRight, maxScore, currentScore+1);
}

// this will recursively loop through all of the different nodes in the tree.
void checkSubtrees(BinaryNode<int> * root, int avl, bool & avlTree)
{
    if (root == NULL && (avl > 1 || avl < -1))
        return;
    else if (root == NULL)
        return;
    
    checkSubtrees(root->pLeft, avl, avlTree);
    checkSubtrees(root->pRight, avl, avlTree);
    
    int scoreLeft = 0;
    int scoreRight = 0;
    getHeight(root->pLeft, scoreLeft, 0);
    getHeight(root->pRight, scoreRight, 0);
    
    if (scoreLeft-scoreRight > 1 || scoreLeft-scoreRight < -1)
        avlTree = false;
}

// main function. Creates a tree and passes that to the above functions.
//int main()
//{
//    int balanceFactor = 0;
//    bool avlTree = true;
//
//    checkSubtrees(myTree, balanceFactor, avlTree);
//    cout << "Tree is: " << (avlTree == true ? "balanced\n" : "unbalanced\n");
//}

/*****************************************************************************
 * Problem: Given a directed graph, design an algorithm to find out whether
 * there is a route between two nodes.
 *****************************************************************************/
void getAdjacencies(vector<list<int>> graph, vector<int> & adjacencies, int startingPoint)
{
    
}

bool mayDaan(bool found, vector<list<int>> graph, int adj1, int adj2)
{
    // let's do a breadth first search
    bool inGraph = false;
    for (int i = 0; i < graph.size(); i++)
    {
        for (list<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
        {
            if ((*it) == adj1)
            {
                inGraph = true;
                break;
            }
        }
        if (inGraph)
            break;
        if (i == (int)graph.size()-1 && !inGraph)
            return false;
    }
    
    // breadth first search
    queue<int> search;
    search.push(adj1);
    while (!search.empty())
    {
        vector<int> adjacencies;
    }
    return found;
}

/*****************************************************************************
 * Problem: Given a sorted order (increasing number) array of unique integers,
 * write an algorithm to create a binary search tree with minimal height.
 *****************************************************************************/
BinaryNode<int>* createTree(vector<int> &arr, int start, int end)
{
    if (end < start)
        return NULL;
    
    int mid = (start + end) / 2;
    BinaryNode<int>* root = new BinaryNode<int>(arr[mid]);
    
    root->pLeft = createTree(arr, start, mid-1);
    root->pRight = createTree(arr, mid+1, end);
    
    return root;
}

template <class T>
void LVR(BinaryNode<T>* p)
{
    if (!p)
        return;
    
    LVR(p->pLeft);
    cout << p->data << ' ';
    LVR(p->pRight);
}

//int main()
//{
//    vector<int> arr;
//    for (int i = 0; i < 10; i++)
//        arr.push_back(i);
//
//    BinaryNode<int>* root;
//
//    root = createTree(arr, 0, 9);
//
//    cout << "{ ";
//    LVR(root);
//    cout << "}\n";
//    return 0;
//}

/****************************************************************************
 * Problem: Find out whether a given tree is a binary search tree by definition:
 * left <= parent < right.
 *****************************************************************************/
bool checkBST(BinaryNode<int>* p, int min, int max)
{
    // anchor case: return true if p is NULL
    if (p == NULL)
        return true;
    
    // compare the node to the current minimums and maximums.
    if ((p->data <= min && min != 0) || (p->data > max && max != 0))
        return false;
    
    // now we need to return false to all stack calls if need be.
    if (!checkBST(p->pLeft, min, p->data) || !checkBST(p->pRight, p->data, max))
        return false;
    
    // if we get down here, then it is definitely a binary search tree. :D
    return true;
}

bool isBinarySearch(BinaryNode<int>* p)
{
    return checkBST(p, 0, 0);
}

//int main()
//{
//    cout << "is: " << (isBinarySearch(myTree) == true ? "BST tree\n" : "not BST tree\n");
//    return 0;
//}

/***************************************************************************
 * Problem: Given a binary tree, design an algorithm which creates a linked
 * list of all the nodes at each depth.
 ****************************************************************************/
void TreeToLists(vector<list<BinaryNode<int>*>> & lists, BinaryNode<int> * p, int level)
{
    if (p == NULL)
        return;
    
    if (lists.size() == level)
    {
        // initialize now a list and put in the first data item
        list<BinaryNode<int>*> newList;
        newList.push_back(p);
        
        lists.push_back(newList);
    }
    else
    {
        lists[level].push_back(p);
    }
    
    TreeToLists(lists, p->pLeft, level+1);
    TreeToLists(lists, p->pRight, level+1);
}

void displayLists(vector<list<BinaryNode<int>*>> & lists)
{
    for (int i = 0; i < lists.size(); i++)
    {
        cout << "{ ";
        for (list<BinaryNode<int>*>::iterator it = lists[i].begin(); it != lists[i].end(); it++)
        {
            if ((*it))
               cout << (*it)->data << ' ';
        }
        cout << "}\n";
    }
}

//int main()
//{
//    vector<list<BinaryNode<int>*>> lists;
//    cout << lists.size() << endl;
//
//    TreeToLists(lists, myTree, 0);
//    displayLists(lists);
//    return 0;
//}

/***************************************************************************
 * Problem: Implement a function to check if a binary tree is balanced.
 * Fo the purposes of this question, a balanced tree is defined as a tree
 * such that the heights of two subtrees of any node never differ by
 * more than one.
 ***************************************************************************/
BinaryNode<int>* findLeftmostNode(BinaryNode<int>* p)
{
    // anal programming: handle the null case
    if (p == NULL)
        return p;
    
    while (p->pLeft)
        p = p->pLeft;
    
    return p;
}

BinaryNode<int>* findSuccessor(BinaryNode<int>* p)
{
    if (p->pRight) {
        p = findLeftmostNode(p->pRight);
    }
    else {
        BinaryNode<int>* q;
        BinaryNode<int>* x;
        q = p;
        x = p->pParent;
        while (x != NULL && x->pLeft != q)
        {
            q = x;
            x = x->pParent;
        }
        return x;
    }
    return p;
}

//int main()
//{
//
//    cout << "Parent is: " << p->data <<  " Successor is: " << findSuccessor(p)->data << endl;
//    return 0;
//}

/**************************************************************************
 * Problem: Design an algorithm and write code to find the first common
 * ancestor of two nodes in a binary tree. Avoid storing additional nodes in a
 * data structure.
 ***************************************************************************/
int depth(BinaryNode<int>* p)
{
    int depth = 0;
    while (p->pParent)
    {
        depth++;
        p = p->pParent;
    }
    return depth;
}

void reduceBig(BinaryNode<int> *& p, int depth)
{
    for (int i = depth; i > 0; i--)
        p = p->pParent;
}

BinaryNode<int>* findIntersection(BinaryNode<int>* one, BinaryNode<int>* two)
{
    BinaryNode<int>* big = (depth(one) > depth(two) ? one : two);
    BinaryNode<int>* small = (depth(two) < depth(one) ? two : one);
    int delta = depth(big) - depth(small);
    
    if (delta > 0)
       reduceBig(big, delta);
    
    while (big != NULL && small != NULL && big != small)
    {
        big = big->pParent;
        small = small->pParent;
    }
    
    return small;
}

//int main()
//{
//    BinaryNode<int>* solved = findIntersection(t, j);
//    cout << "Nodes: " << t->data << " and " << j->data << " intersect at " << solved->data << endl;
//
//    return 0;
//}

/*************************************************************************
 * Problem: Display all versions of an array that grain from a binary
 * search tree.
 **************************************************************************/
void addAll(list<int> & toThis, list<int> fromHere)
{
    for (list<int>::iterator it = fromHere.begin(); it != fromHere.end(); it++)
    {
        toThis.push_back((*it));
    }
}

void recurseTree(BinaryNode<int>* p, list<int> &v)
{
    // visit-left-right recursion.
    if (p == NULL)
        return;
    
    // visit node
    v.push_back(p->data);
    
    // go left and then right
    recurseTree(p->pLeft, v);
    recurseTree(p->pRight, v);
}

void weaveLists(BinaryNode<int>* root, list<int> v1, list<int> v2, list<int> sublists)
{
    if ((int)v1.size() == 0 || (int)v2.size() == 0)
    {
        list<int> result(sublists);
        addAll(sublists, v1);
        addAll(sublists, v2);
        cout << "{ " << root->data << ' ';
        for (list<int>::iterator it = sublists.begin(); it != sublists.end(); it++)
        {
            cout << (*it) << ' ';
        }
        cout << "}\n";
        return;
    }
    
    sublists.push_back(v1.front());
    int v1Data = v1.front();
    v1.pop_front();
    weaveLists(root, v1, v2, sublists);
    sublists.pop_back();
    v1.push_front(v1Data);
    
    sublists.push_back(v2.front());
    int v2Data = v2.front();
    v2.pop_front();
    weaveLists(root, v1, v2, sublists);
    sublists.pop_back();
    v2.push_front(v2Data);
    
    return;
}

void allSequences(BinaryNode<int>* root)
{
    list<int> v1;
    list<int> v2;
    
    if (root->pLeft)
       recurseTree(root->pLeft, v1);
    
    if (root->pRight)
       recurseTree(root->pRight, v2);
    
    list<int> sublists;
    weaveLists(root, v1, v2, sublists);
}
/*****************************************************************
 * Problem: Create a function to get a random node from a binary
 * tree.
 ******************************************************************/
BinaryNode<int>* getRandomNode(BinaryNode<int>* p, int randNum)
{
    if (p == NULL)
        return NULL;
    
    static int funcCalls = 0;
    BinaryNode<int>* q = NULL;
    if (funcCalls == randNum)
        q = p;
    funcCalls++;
    if (q)
       return q;
    
    q = getRandomNode(p->pLeft, randNum);
    
    if (q != NULL)
        return q;
    
    q = getRandomNode(p->pRight, randNum);
    return q;
}

//int main()
//{
//    BinaryNode<int>* p = new BinaryNode<int>(100);
//    p->addLeft(50);
//    p->addRight(200);
//    p = p->pLeft;
//    p->addLeft(25);
//    p->addRight(35);
//    p = p->pParent->pRight;
//    p->addLeft(150);
//    p->addRight(400);
//    p = p->pParent;
//    int randInt = rand();
//    int sizeP = (int)p->size();
//    randInt = randInt % sizeP;
//    
//    BinaryNode<int>* randNode = getRandomNode(p, randInt);
//    cout << "Random node points to:: " << randNode->data << endl;
//}
