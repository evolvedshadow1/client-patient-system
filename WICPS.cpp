/*
 * WICPS.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 *
 * Last modified on: June 2017
 * Author: John Zheng
 */

#include "List.h"
#include "Patient.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Description: Add a new patient to the system via carecard number.
//Postcondition: New patient added to the system.
void new_patient(List * thePatients){
  string a_carecard = "";
  int pos;
  bool carecard_digit = false;
  cout << "Please enter your carecard number: ";
  while(carecard_digit == false){
    getline(cin >> ws, a_carecard);
    for(pos=0;pos<a_carecard.length();pos++){
      if(isdigit(a_carecard[pos]) != true){
        cout << "Please enter a correct carecard number: ";
        break;
      }if((pos == a_carecard.length()-1) && (isdigit(a_carecard[pos]) == true)){
        carecard_digit = true;
      }
    }
  }
  Patient a_patient(a_carecard);
  if(thePatients->insert(a_patient)){
    cout << "Patient " << a_carecard << " has joined the client patient system." << endl;
  }else{
    cout << "The carecard number is invalid, or the patient is already in the system.\n" << endl;
  }
}

//Description: Remove a patient from the system via carecard number.
//Precondition: Carecard number is registered.
//Postcondition: Carecard number is removed from the system.

void remove_patient(List * thePatients){
  string a_carecard = "";
  cout << "Please enter the patient's carecard number that you wish to delete: ";
  getline(cin >> ws, a_carecard);
  Patient a_patient(a_carecard);
  if(thePatients->remove(a_patient)){
    cout << "Patient " << a_carecard << " has been removed from the client patient system.\n" <<endl;
  }else{
    cout << "That number is not registered.\n" << endl;

  }
}

//Description: Search for a patient in the system via carecard number, and print the patient's record.
//Precondition: Patient is in the system.
//Postcondition: Patient's record is printed.
void search_patient(List * thePatients){
  string a_carecard = "";
  cout << "Please enter the patient's carecard number: ";
  getline(cin >> ws, a_carecard);
  Patient a_patient(a_carecard);
  if(thePatients->search(a_patient) != NULL){
    cout << a_carecard << " is in our client patient system." << endl;
    thePatients->search(a_patient)->printPatient();
  }else{
    cout << a_carecard << " is not in our client patient system." << endl;
  }
}

//Description: Modify a patient's record.
//Precondition: Patient is in the system.
//Postcondition: Patient's record is modified.
void modify_patient(List * thePatients){
  char inp = 0;
  string a_carecard = "", a_name = "", a_address = "", a_phone = "", a_email = "";
  cout << "Please enter the patient's carecard number: ";
  getline(cin >> ws, a_carecard);
  Patient a_patient(a_carecard);
  while (inp != 'f'){
  if(thePatients->search(a_patient) != NULL){
      cout << "What would you like to modify?" << endl;
      cout << "To change the patient's name, press n\n";
      cout << "To change the patient's address, press a\n";
      cout << "To change the patient's phone number, press p\n";
      cout << "To change the patient's email, press e\n";
      cout << "To go back, press f" << endl;
      cin >> inp;
      inp = tolower(inp);
      switch(inp){
        case 'n': cout << "Please enter your name: ";
                  getline(cin >> ws, a_name);
                  thePatients->search(a_patient)->setName(a_name);
                  cout << "\nName changed." << endl;
                  break;
        case 'a': cout << "Please enter your address: ";
                  getline(cin >> ws, a_address);
                  thePatients->search(a_patient)->setAddress(a_address);
                  cout << "\nAddress changed." << endl;
                  break;
        case 'p': cout << "Please enter your phone number: ";
                  getline(cin >> ws, a_phone);
                  thePatients->search(a_patient)->setPhone(a_phone);
                  cout << "\nPhone number changed." << endl;
                  break;
        case 'e': cout << "Please enter your email: ";
                  getline(cin >> ws, a_email);
                  thePatients->search(a_patient)->setEmail(a_email);
                  cout << "\nEmail changed." << endl;
                  break;
        case 'f': break;
        default: cout << "That's not a valid input" << endl;
      }
    }else{
      cout << "There is no patient with carecard " << a_carecard << " in the patient client system." <<endl;
    }
  }
}
//Description: Prints all current patients and their records.

void print_patient(List * thePatients){
  thePatients->printList();
}

int main(){

  List* patients = new List();

  bool end = false;
  char input = 0;

  while(end == false){
    cout << "Welcome to the client patient system.\n";
    cout << "To enter a new patient into the system, press e\n";
    cout << "To remove a patient from the system, press r\n";
    cout << "To search for a patient, press s\n";
    cout << "To modify a patient's record, press m\n";
    cout << "To see a list of current patients, press l\n";
    cout << "To exit the client patient system, press f\n";
    cout << "Please choose an option: ";
    cin >> input;
    input = tolower(input);
    switch(input){
      case 'e': new_patient(patients); break;
      case 'r': remove_patient(patients); break;
      case 's': search_patient(patients); break;
      case 'm': modify_patient(patients); break;
      case 'l': print_patient(patients); break;
      case 'f': cout << "\nEnding program...\n"; end = true; break;
      default: cout << "\nPlease enter a valid input.\n" << endl;
      }
  }
//end of WICPS.cpp
  cout << "There are currently " << patients->getElementCount() << " patients." << endl;

  return 0;
}
