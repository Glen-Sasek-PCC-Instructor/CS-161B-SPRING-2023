/******************************************************************************
# Author:           Raul Mejia.
# Assignment:      assigment 2  (CS161B)
# Date:             April 12, 2023
# Description:     This program will ask you a few questions and generate an
encoded fileName based on your answers # Input: Output:

# Sources:          Assignment 2 specification, youtube and  class mate.
#
#******************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;
void welcome();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);

int main() {
  char encodeFileName[50];
  char option;
  welcome();
  do {
    option = displayMenu();
    if (option == 'E' || option == 'e') {
      encode(encodeFileName);
      cout << "Your encoded file name is: " << encodeFileName << endl;
    } else if (option == 'q' || option == 'Q') {
      cout << "Thank you for using my fileName generator!" << endl;
      return 0;
    }
  } while (option != 'q' || option != 'Q');
}

void welcome() { cout << "Welcome to my fileName encoding program!!" << endl; }
char displayMenu() {
  char option;
  cout << "Please pick an option below: " << endl;
  cout << "(e)Encode a file name" << endl;
  cout << "(q)quit" << endl;
  cin >> option;
  while (option != 'E' && option != 'e' && option != 'q' && option != 'Q') {
    cout << "Invalid option! Please try again!!" << endl;
    cin >> option;
  }
  return option;
}
void encode(char encodeFileName[]) {
  char fName[20];
  char lName[20];
  bool lateFlag;
  char parsedID[5];
  char fileName[20];
  char strTime[5];
  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime(strTime);
  strncpy(encodeFileName, lName, 20);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fName);
  strcat(encodeFileName, "_");
  if (lateFlag) {
    strcat(encodeFileName, "Late");
  }
  strcat(encodeFileName, "_");
  strcat(encodeFileName, parsedID);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, strTime);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fileName);
}
void readTime(char strTime[]) {
  int hours;
  int mints;
  char discard;
  cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): "
       << endl;
  cin >> hours >> discard >> mints;
  while (!cin || discard != ':') {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hours >> discard >> mints;
  }
  cin.ignore(100, '\n');
  strncpy(strTime, to_string(hours).c_str(), 5);
  strcat(strTime, to_string(mints).c_str());
}
void readInput(char fName[], char lName[], bool &lateFlag) {
  char late;
  cout << "This program will ask you a few questions and generate an encoded "
          "fileName based on your answers."
       << endl;
  cout << "Enter your last name: ";
  cin >> lName;
  cout << "Enter your first name:";
  cin >> fName;
  cout << "Was your assignment Late (y/n)? ";
  cin >> late;
  while (late != 'Y' && late != 'y' && late != 'N' && late != 'n') {
    cout << "Invalid option! Please try again!!" << endl;
    cin >> late;
  }
  if (late == 'y' or late == 'Y') {
    lateFlag = true;
  } else {
    lateFlag = false;
  }
}
void readInput(char parsedID[], char fileName[]) {
  char ID[20];
  cout << "Enter your Student-ID (format: 222-22-2222):";
  cin >> ID;
  cout << "Enter the file name: ";
  cin >> fileName;
  strncpy(parsedID, ID + 7, 5);
}
