/*
 * List.h
 *
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: June 2017
 * Author: John Zheng
 */

#pragma once
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:
  Patient ** elements = new Patient*[10]; //data structure that includes all the arrays of
  Patient* arr0 = new Patient[4];         //difference carecard numbers (begins with 0-9)
  Patient* arr1 = new Patient[4];
  Patient* arr2 = new Patient[4];
  Patient* arr3 = new Patient[4];
  Patient* arr4 = new Patient[4];
  Patient* arr5 = new Patient[4];
  Patient* arr6 = new Patient[4];
  Patient* arr7 = new Patient[4];
  Patient* arr8 = new Patient[4];
  Patient* arr9 = new Patient[4];
	int elementCount[10];                  //Current count of elements in the array
	int capacity[10];                      //Maximum capacity of elements in the array


public:

// We must add at least 1 constructor and a destructor

	// Default constructor
	List();

  //Copy constructor
  List(const List& l);

  //destructor
  ~List();

// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate
    //              a new element. This is done unbeknown to the client code.
	//              If the insertion is successful, true is returned otherwise, false is returned.
	// Precondition: newElement must not already be in data collection.
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
	bool insert(const Patient& newElement);

	// Description: Remove an element.
	//              If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.
	bool remove( const Patient& toBeRemoved );

	// Description: Remove all elements.
	void removeAll();

	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);

	// Description: Prints all n elements stored in List in sort order and does so in O(n).
	void printList();

// *** End of Public Interface ***

}; // end List
