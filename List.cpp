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
#include "List.h"
#include <iostream>
using namespace std;

// We must add at least 1 constructor and a destructor

// Default constructor
List::List(){
  int pos;
  for(pos=0;pos<10;pos++){
    elementCount[pos] = 0;  //set elementCount to 0 for all arrays
    capacity[pos] = 4;      //set default capacity to 4 for all arrays
  }
  elements[0] = arr0;
  elements[1] = arr1;
  elements[2] = arr2;
  elements[3] = arr3;
  elements[4] = arr4;
  elements[5] = arr5;
  elements[6] = arr6;
  elements[7] = arr7;
  elements[8] = arr8;
  elements[9] = arr9;
}
//Copy Constructor

List::List(const List& l){
  int pos;
  for(pos=0;pos<10;pos++){
    elementCount[pos] = l.elementCount[pos];
    capacity[pos] = l.capacity[pos];
  }
  elements[0] = l.arr0;
  elements[1] = l.arr1;
  elements[2] = l.arr2;
  elements[3] = l.arr3;
  elements[4] = l.arr4;
  elements[5] = l.arr5;
  elements[6] = l.arr6;
  elements[7] = l.arr7;
  elements[8] = l.arr8;
  elements[9] = l.arr9;
}

// destructor

List::~List(){    //removes all the memory needed for the patients
  delete[] arr0;
  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;
  delete[] arr5;
  delete[] arr6;
  delete[] arr7;
  delete[] arr8;
  delete[] arr9;
}

// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

// Description: Returns the total element count currently stored in List.

int List::getElementCount() const{
  int total = 0;
  int pos;
  for(pos=0;pos<10;pos++){
    total = total + elementCount[pos];
  }
  return total;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate
  //              a new element. This is done unbeknown to the client code.
	//              If the insertion is successful, true is returned otherwise, false is returned.
	// Precondition: newElement must not already be in data collection.
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
  bool List::insert(const Patient& newElement){
    int pos, pos2, position, dig;
    Patient temp;
    bool inData = false;
    string tmp = newElement.getCareCard();
    char a = tmp[0];
    switch(a){
        case '0' : dig = 0;
        case '1' : dig = 1;
        case '2' : dig = 2;
        case '3' : dig = 3;
        case '4' : dig = 4;
        case '5' : dig = 5;
        case '6' : dig = 6;
        case '7' : dig = 7;
        case '8' : dig = 8;
        case '9' : dig = 9;
    }

    for(pos=0;pos<elementCount[dig];pos++){   //checks to see if patient is already in the system
      if(elements[dig][pos].getCareCard() == newElement.getCareCard()){
        cout << "newElement is already in the data collection" << endl;
        inData = true;
        break;
      }
    }
    if(inData != true){

      if((elementCount[dig]+1) > capacity[dig]){
        capacity[dig] = (capacity[dig])*2;   //doubles the orignial capacity if elementCount > capacity (expands the array).
        Patient* tmp = new Patient[capacity[dig]];
        for(pos=0;pos<elementCount[dig];pos++){
          tmp[pos] = elements[dig][pos];
        }
        delete[] elements[dig];
        elements[dig] = tmp;
      }

      elementCount[dig]++;
      elements[dig][(elementCount[dig])-1] = newElement;

        for(pos=0;pos<elementCount[dig]-1;pos++){   //selectionsort the array so carecard number is in ascending order.
          position = pos;
          for(pos2=pos+1;pos2<elementCount[dig];pos2++){
            if(elements[dig][position].operator>(elements[dig][pos2])){
              position = pos2;
            }
          }
          if(position != pos){
            temp = elements[dig][pos];
            elements[dig][pos] = elements[dig][position];
            elements[dig][position] =  temp;
          }

        }
        return true;
    }
    return false;
    }


	// Description: Remove an element.
	//              If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.

  bool List::remove(const Patient& toBeRemoved){
    int pos, location, dig;
    bool inData = false;
    string tmp = toBeRemoved.getCareCard();
    char a = tmp[0];
    switch(a){
        case '0' : dig = 0;
        case '1' : dig = 1;
        case '2' : dig = 2;
        case '3' : dig = 3;
        case '4' : dig = 4;
        case '5' : dig = 5;
        case '6' : dig = 6;
        case '7' : dig = 7;
        case '8' : dig = 8;
        case '9' : dig = 9;
    }
    for(pos=0;pos<elementCount[dig];pos++){
      if(elements[dig][pos].getCareCard() == toBeRemoved.getCareCard()){
        inData = true;
        location = pos;
        break;
      }else{
        inData = false;
      }
    }
    if(inData == true){
      for(pos=location+1;pos<elementCount[dig];pos++){
        elements[dig][pos-1] = elements[dig][pos];
      }
      elementCount[dig]--;
      return true;
    }
    return false;
  }

	// Description: Remove all elements.
  void List::removeAll(){
    int pos;
    for(pos=0;pos<10;pos++){
      elementCount[pos] = 0;
    }
  }
	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
  Patient* List::search(const Patient& target){
    string tmp = target.getCareCard();
    char a = tmp[0];
    int pos, dig;
    switch(a){
        case '0' : dig = 0;
        case '1' : dig = 1;
        case '2' : dig = 2;
        case '3' : dig = 3;
        case '4' : dig = 4;
        case '5' : dig = 5;
        case '6' : dig = 6;
        case '7' : dig = 7;
        case '8' : dig = 8;
        case '9' : dig = 9;
    }

    for(pos=0;pos<elementCount[dig];pos++){
      if(elements[dig][pos].getCareCard() == target.getCareCard()){
        return &elements[dig][pos];
      }
    }
    return NULL;
  }
	// Description: Prints all n elements stored in List in sort order and does so in O(n).

  void List::printList(){
    int pos, pos2;
    for(pos2=0;pos2<10;pos2++){
      for(pos=0;pos<elementCount[pos2];pos++){
        cout << elements[pos2][pos].getCareCard() << ", ";
        cout << "Patient: " << elements[pos2][pos].getName() << ", ";
        cout << elements[pos2][pos].getAddress() << ", ";
        cout << elements[pos2][pos].getPhone() << ", ";
        cout << elements[pos2][pos].getEmail() << endl;
      }

    }
  }

// *** End of Public Interface ***
// end List
