/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jon Michael Ossola
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
	Node <T> * n = NULL;
	Node <T> * p;

	for (int i = 0; i < num; i++)
	{
		// if n is null or needs to go in the first spot, put it there.
		if (n == NULL || n->data > array[i])
		{
			insert(array[i], n, true);
		}
		else 
		{
			for (p = n; p; p = p->pNext)
			{
				// if pNext is null and the array item is still bigger,
				// put it in the back spot.
				if (p->pNext == NULL && array[i] > p->data)
				{
					insert(array[i], p);
					break;
				}
				else if (array[i] > p->data && array[i] <= p->pNext->data)
				{
					// check to make sure that this is the perfect middle spot.
					// then, put the array item into the linked list.
					insert(array[i], p);
					break;
				}
			}
		}
	}

	// now put everything back into the original array.
	Node <T> * traverse = n;
	for (int i = 0; i < num && traverse; i++)
	{
		array[i] = traverse->data;

		traverse = traverse->pNext;
	}
	// don't want any memory leaks
	freeData(n);
}

#endif // INSERTION_SORT_H

