#ifndef BAG_H
#define BAG_H

/***********************************************************
 * Class: Bag
 * Description: Holds ints...for now
 ***********************************************************/
template <class T>
class Bag
{
private:
   int capacity;
   int size;
   T* data;

public:
	//~Bag();
   Bag()
   {
   	size = 0;
   	data = new T[5];
   	capacity = 5;
   } // Default constructor
				
   // Getters
   int getCapacity() const { return capacity; }
   int getCount() const { return size; }

   T getItem(int index) const { return data[index]; }
   int find(const T &item) const;
   void addItem(const T &item);
   void deleteItem(const int index);
};

template <class T>
void Bag<T>::addItem(const T &item)
{
   	if (size < capacity)
   	{
   		data[size] = item;
   		size++;
   	}
   	else if (size >= capacity)
   	{
   		capacity *= 2;
   		T* newData = new T[capacity];

   		for (int i = 0; i < size; i++)
   		{
   			newData[i] = data[i];
   		}

   		delete [] data;

   		data = newData; 

   		data[size] = item;
   		size++;
   	}

}

template <class T>
int Bag<T>::find(const T &item) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == item)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
void Bag<T>::deleteItem(const int index)
{
	if (index < size)
	{
		for (int i = index; i<size-1; i++)
		{
			data[i] = data[i+1];
		}
		size--;
	}
}

#endif

