// Implementation file for the IntegerList class.
#include <iostream>
#include <cstdlib>
#include "IntegerList.h"
using namespace std;

//***********************************************************
// The constructor sets each element to zero.               *
//***********************************************************
IntegerList::IntegerList(int size)
{ 
   list = new int[size];
   numElements = size;
   for (int ndx = 0; ndx < size; ndx++)
      list[ndx] = 0;
}

//copy constructor
IntegerList::IntegerList(const IntegerList& other)
{
	numElements = other.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
	{
		list[i] = other.list[i];
	}
	cout << "The copy constructor is now running." << endl;
}

// deletes the dynamically allocated memory
IntegerList::~IntegerList()
{
	delete[] list;
	cout << endl << "The destructor is now running." << endl;
}

// assignment operator
IntegerList IntegerList::operator = (const IntegerList& other)
{
	if (this != &other)
	{
		delete[] list;
		numElements = other.numElements;
		list = new int[numElements];
		for (int i = 0; i < numElements; i++)
		{
			list[i] = other.list[i];
		}
	}
	return *this;
	// this does not return *this, not sure how to do that without an error somewhere
	// with this being IntegerList and not void and returning *this, the numbers do not copy the right way
}

//***********************************************************
// isValid member function.                                 *
// This private member functon returns true if the argument *
// is a valid subscript, or false otherwise.                *
//***********************************************************

bool IntegerList::isValid(int element) const
{
   bool status;

   if (element < 0 || element >= numElements)
      status = false;
   else
      status = true;
   return status;
}

//***********************************************************
// setElement member function.                              *
// Stores a value in a specific element of the list. If an  *
// invalid subscript is passed, the program aborts.         *
//***********************************************************

void IntegerList::setElement(int element, int value)
{
   if (isValid(element))
      list[element] = value;
   else
   {
      cout << "Error: Invalid subscript\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// getElement member function.                              *
// Returns the value stored at the specified element.       *
// If an invalid subscript is passed, the program aborts.   *
//***********************************************************

int IntegerList::getElement(int element) const
{
   if (isValid(element))
      return list[element];
   else
   {
      cout << "Error: Invalid subscript\n";
      exit(EXIT_FAILURE);
   }
}

int IntegerList::getNumElements() const
{
	return numElements;
}