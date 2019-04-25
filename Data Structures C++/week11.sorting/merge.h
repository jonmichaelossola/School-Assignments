/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
*
* Author:
*   Jon Michael Ossola 
* Summary: 
*	Heap sort and merge sort
************************************************************************/
#include <list>
   
using namespace std;


/***********************************************************************
* Display function. Display the items within the list, using set width
* function, as well as printing out a new line.
************************************************************************/
template <class T>
void display(const list<T> &data)
{
	int i = 1;

	for (list<int>::const_iterator it = data.begin(); it != data.end(); it++, i++)
	{
		cout << setw(3) << *it;
		if (i % 10 == 0)
			cout << endl;
	}
}

/************************************************************************
* Join the merge lists. We can do this by keeping track of which sublist
* we are on and comparing each sublist and then joining them onto 
* our data list.
*************************************************************************/
template <class T>
void mergeJoin(list<T> &data, list<T> &f1, list<T> &f2, int &numSublist)
{
	numSublist = 0;

	// don't want anything on our data list, that's where we store our data.
	data.clear();

	// declare our iterators and previous pointers.
	list<int>::iterator it = f1.begin();
	T itPrevious = f1.front();
	
	list<int>::iterator it2 = f2.begin();
	T it2Previous = f2.front();

	//loop through the sublists
	while (it != f1.end() && it2 != f2.end())
	{
		// break from the while loop as soon as one has hit end of sublist.
		while (*it >= itPrevious && *it2 >= it2Previous && !(it == f1.end() && it2 == f2.end()))
		{
			if (*it <= *it2)
			{
				data.push_back(*it);
				itPrevious = *it;
				it++;
			}
			else if (*it2 < *it)
			{
				data.push_back(*it2);
				it2Previous = *it2;
				it2++;
			}
		}

		// copy over everything else from the sublist
		if (*it <= itPrevious)
		{
			while (*it2 >= it2Previous && it2 != f2.end())
			{
				data.push_back(*it2);
				it2Previous = *it2;
				it2++;
			}
		}
		if (*it2 <= it2Previous)
		{
			while (*it >= itPrevious && it != f1.end())
			{
				data.push_back(*it);
				itPrevious = *it;
				it++;
			}
		}

		itPrevious = *it;
		it2Previous = *it2;
		numSublist++;
	}

	// if we hit the end of one of the sublists and need to copy
	// over everything from the other list, do the following.
	while (it == f1.end() && it2 != f2.end())
	{
		if (*it2 == it2Previous)
			numSublist++;
		data.push_back(*it2);
		it2++;
	}
	while (it2 == f2.end() && it != f1.end())
	{
		if (*it == itPrevious)
			numSublist++;
		data.push_back(*it);
		it++;
	}
}

/************************************************************************
* Merge split function. Divide the data we have into the two lists, and 
* organize them by their sublists. Then since we are passing all of the
* lists by reference, we can just make the function void.
*************************************************************************/
template <class T>
void mergeSplit(list<T> &data, list<T> &f1, list<T> &f2)
{
	if (!f1.empty())
	   f1.clear();
	if (!f2.empty())
	   f2.clear();

	list<int>::iterator it = data.begin();
	int i = data.size();
	T previous = data.front();

	while (it != data.end())
	{
		if (i % 2 == 0)
		{
			if (*it < previous)
			{
				f1.push_back(*it);
				previous = *it;
				it++;
			}
			// push a sublist onto the first list.
			while (*it >= previous)
			{
				f1.push_back(*it);
				previous = *it;
				it++;
			}
			i--;
		}
		else
		{
			if (*it < previous)
			{
				f2.push_back(*it);
				previous = *it;
				it++;
			}
			// push sublist onto the second list
			while (*it >= previous)
			{
				//cout << "Endless loop merge split function\n";
				f2.push_back(*it);
				previous = *it;
				it++;
			}
			i--;
		}
	}
}

/*************************************************************************
* This function sorts a linked list using a Natural Merge Sort.
* Input:  data -  linked list of data to be sorted.
* Output: data -  sorted linked list
**************************************************************************/
template<class T>
void mergeSort(list<T> &data)
{
	// if there's one or less data item in the list, we have nothing to do.
	if (data.size() <= 1)
		return;

	int subList = 2;

	list<T> f1;
	list<T> f2;

	while (subList != 1)
	{
		mergeSplit(data, f1, f2);
		mergeJoin(data, f1, f2, subList);
	}

	display(data);
}