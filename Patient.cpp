/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Last modified on: June 2017
 * Author: John Zheng
 */

#include <iostream>
#include "Patient.h"
#include <string>
#include <locale>
using namespace std;
// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient(){
  name = "To be entered";
  address = "To be entered";
  phone = "To be entered";
  email = "To be entered";
  careCard = "0000000000";
}
// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard){
  name = "To be entered";
  address = "To be entered";
  phone = "To be entered";
  email = "To be entered";
  if(aCareCard.length() != 10){
      careCard = "0000000000";
  }else{
    careCard = aCareCard;
  }
}
// Getters and setters
// Description: Returns patient's name.
string Patient::getName() const{
  return name;
}

// Description: Returns patient's address.
string Patient::getAddress() const{
  return address;
}

// Description: Returns patient's phone number.
string Patient::getPhone() const{
  return phone;
}
// Description: Returns patient's email.
string Patient::getEmail() const{
  return email;
}
// Description: Returns patient's care card number.
string Patient::getCareCard() const{
  return careCard;
}
// Description: Sets the patient's name.
void Patient::setName(const string aName){
  locale loc;
  if(!aName.empty() && (isalpha(aName[0], loc))){
    name = aName;
  }
}
// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress){
  address = anAddress;
}
// Description: Sets the patient's phone number.
void Patient::setPhone(const string aPhone){
  if(aPhone.length() == 10){
      phone = aPhone;
  }
}
// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail){
  email = anEmail;
}
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator==(const Patient & rhs){
  if(careCard == rhs.getCareCard()){
    return true;
  }else{
    return false;
  }
}
// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
bool Patient::operator>(const Patient & rhs){
  int pos;
  for(pos=0;pos<10;pos++){
  if(careCard[pos] > rhs.getCareCard()[pos]){
    return true;
  }if(careCard[pos] == rhs.getCareCard()[pos]){
    continue;
  }else{
    return false;
    }
  }
}
// Description: Prints the content of "this" patient.
void Patient::printPatient(){
  cout << careCard << ", ";
  cout << "Patient: " << name << ", ";
  cout << address << ", ";
  cout << phone << ", ";
  cout << email << endl;
}
// end of Patient.cpp
