/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
*
* Author:
*   Jon Michael Ossola
* Summary: 
*
************************************************************************/
#include <vector>
   
using namespace std;


/*************************************************************************
* Simple display function. Set the width to 3 before each data item. Print
* a new line after every 10 items.
**************************************************************************/
template <class T>
void display(const vector<T> &data)
{
	for (int i = 1; i < data.size(); i++)
	{
		cout << setw(3) << data[i];
		if (i % 10 == 0)
			cout << endl;
	}
}

/*************************************************************************
* Percolate down function. We changed the tree, so we need to make it a heap
* again (or we are heapifying the tree). Let's use this percolate down 
* function to fix our tree, heapifying it and all that jazz.
**************************************************************************/
template<class T>
void percolateDown(vector<T> &data, int parent, int sizeData)
{
	int child = parent * 2;

	while (child <= sizeData-1)
	{
		if (child < sizeData-1 && data[child] < data[child+1])
		{
			child++;
		}
		else if (data[parent] < data[child])
		{
			T tmp = data[parent];
			data[parent] = data[child];
			data[child] = tmp;
			parent = child;
			child *= 2;
		}
		else
			return;
	}
}

/**************************************************************************
* Heapify function. We pass in a vector, and the heapify function calls
* the percolate down function over and over until we have heapified the 
* tree, making all parent nodes greater than or equal to their children.
***************************************************************************/
template<class T>
void heapify(vector<T> &data)
{
	// start percolating from max item in vector / 2
	// don't forget that the children are parent * 2 and parent * 2 + 1
	for (int start = (data.size()-1) / 2; start != 0; start--) 
	{
		percolateDown(data, start, data.size());
	}
}

/**************************************************************************
* The heap sort function. We are going to heapify the vector first, and 
* then we will exchange the leaf nodes with the root until the entire
* vector is sorted.
**************************************************************************/
template<class T>
void heapSort(vector<T> &data)
{
	// no need to sort anything! That'd be a waste of time.. 
	if (data.size() == 1)
		return;

	    heapify(data);
	
	// root leaf exchange, prune the leaf, percolate down and fix items.
    for (int i = data.size()-1; i >= 1; i--) {
  	   T tmp = data[i];
  	   data[i] = data[1];
  	   data[1] = tmp;

  	   // percolate down
  	   percolateDown(data, 1, i);
    }

    display(data);
}

