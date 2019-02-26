// the memory leak occurs because there is dynamic memory allocation without deleting the allocated memory at the end
// this also needs a copy constructor

#include "IntegerList.h"
#include <iostream>
using namespace std;

void display(IntegerList b)
{
	for (int i = 0; i < b.getNumElements(); i++)
		cout << b.getElement(i) << endl;
}

int main()
{
	const int SIZE = 5;
	IntegerList a(SIZE);
	IntegerList b(10);

	// just put some numbers in to test it
	for (int i = 0; i < SIZE; i++)
		a.setElement(i, i * 2);

	cout << "before assignment" << endl;
	b = a;		// uses the overloaded assignment operator
	cout << "after assignment" << endl;

	cout << "A's values:" << endl;
	display(a);

	cout << endl << "B's values:" << endl;
	display(b);

	// the destructor runs an extra 2 times after compiling a and b, is that okay?
	// is the copy constructor being called anywhere?

	return 0;
}