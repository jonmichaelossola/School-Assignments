#include <iostream>
using namespace std;
//#include <vector>


void nSquared(int array [])
{
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			cout << "(" << array[i] << ", " << array[j] << ")" << endl;
		}
	}
}

int main()
{
	int array[8];
	for (int i = 0; i < 8; i++)
	{
		array[i] = i;
	}

	nSquared(array);

	return 0;
}
