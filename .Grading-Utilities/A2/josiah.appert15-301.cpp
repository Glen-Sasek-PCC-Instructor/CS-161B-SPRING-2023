/******************************************************************************
# Author:           Josiah Appert
# Assignment:       a02
# Date:             April 16, 2023
# Description:      This program creates an appropriate filename based upon
#                   input taken from the user. To do so, it demonstrates use
#                   of string functions from the cstring library, character
#                   arrays, overloaded functions, and functions with value and
#                   reference parameters.
# Input:            menuChoice as character, lName as character array, fName
#                   as character array, isLate as character, stdID as
#                   character array, fileName as character array, hourVar as
#                   integer, discardColon as character, minVar as integer
# Output:           encodeFileName as character array
# Sources:          zyBooks ch 8-10, Assignment 2 guidelines
#******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

const char MAX_STRING = 20;

void welcome();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lname[], bool &lateFlag);
void strToLower(char strLower[]);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);

// Name:	  main()
// Desc:	  This function calls functions to print a welcome message, prompt
//          the user to continue to encoding function or quit, and displays
//          farewell message.
// input:   none
// output:	character array encodeFileName
// return:	integer 0
int main() {
  char encodeFileName[50];
  welcome();
  while (displayMenu() == 'e') {
    encode(encodeFileName);
    cout << "Your encoded file name is: " << encodeFileName << endl << endl;
  }
  cout << endl << "Thank you for using my fileName generator!" << endl;
  return 0;
}

// Name:	  welcome()
// Desc:	  This function prints a welcome message followed by a blank line
// input:   none
// output:	none
// return:	void
void welcome() {
  cout << "Welcome to my fileName encoding program!!" << endl << endl;
}

// Name:	  displayMenu()
// Desc:	  This function displays initial menu for the user, validates entry
// input:   character menuChoice
// output:	none
// return:	character menuChoice
char displayMenu() {
  char menuChoice;
  do {
    cout << "Please pick an option below:" << endl;
    cout << "(e)Encode a file name" << endl;
    cout << "(q)quit" << endl;
    cin >> menuChoice;
    menuChoice = tolower(menuChoice);
    if (!cin || menuChoice != 'q' && menuChoice != 'e') {
      cout << "Invalid option! Please try again!!" << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
  } while (!cin || menuChoice != 'q' && menuChoice != 'e');
  return menuChoice;
}

// Name:	  encode()
// Desc:	  This function calls functions to request user input and encode to a
//          filename
// input:   none
// output:	none
// return:	void
void encode(char encodeFileName[]) {
  char fName[MAX_STRING];
  char lName[MAX_STRING];
  bool lateFlag;
  char parsedID[MAX_STRING];
  char fileName[MAX_STRING];
  char strTime[MAX_STRING];
  cout << "This program will ask you a few questions and generate an" << endl;
  cout << "encoded fileName based on your answers." << endl << endl;
  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime(strTime);
  strncpy(encodeFileName, lName, 10);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fName);
  strcat(encodeFileName, "_");
  if (lateFlag == true) {
    strcat(encodeFileName, "LATE_");
  }
  strcat(encodeFileName, parsedID);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, strTime);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fileName);
  strcat(encodeFileName, "\0");
}

// Name:	  readInput()
// Desc:	  This function requests and validates user input for first and last
//          name and whether assignment was late
// input:   character arrays lName and fName, character isLate, 
// output:	none
// return:	void
void readInput(char fName[], char lName[], bool &lateFlag) {
  char isLate;
  cout << "Enter your last name: ";
  cin >> lName;
  strToLower(lName);
  cout << endl;
  cout << "Enter your first name: ";
  cin >> fName;
  strToLower(fName);
  cout << endl;  
  do {
    cout << "Was your assignment Late (y/n)? ";
    cin >> isLate;
    isLate = tolower(isLate);
    if (isLate != 'y' && isLate != 'n') {
      cout << "Invalid option! Please try again!!" << endl;
    }
    else if (isLate == 'y') {
      lateFlag = true;
    }
    else {
      lateFlag = false;
    }
  } while (isLate != 'y' && isLate != 'n');
  cout << endl;
}

// Name:	  strToLower()
// Desc:	  This function converts character arrays to all lowercase
// input:   none
// output:	none
// return:	void
void strToLower(char strLower[]) {
  for (int i = 0; i < strlen(strLower); ++i) {
    strLower[i] = tolower(strLower[i]);
  }
}

// Name:	  readInput()
// Desc:	  This function prompts the user for their student ID and filename
// input:   character array stdID, characterArray fileName
// output:	none
// return:	void
void readInput(char parsedID[], char fileName[]) {
  char stdID[MAX_STRING];
  cout << "Enter your Student-ID (format: 222-22-2222): ";
  cin >> stdID;
  strncpy(parsedID, stdID + 7, 4);
  cout << endl;
  cout << "Enter the file name: ";
  cin >> fileName;
  cout << endl;
}

// Name:	  readTime()
// Desc:	  This function reads the time from input and validates
// input:   integer hourVar, integer minVar, character discardColon
// output:	none
// return:	void
void readTime(char strTime[]) {
  int hourVar = 0;
  int minVar = 0;
  char discardColon;
  cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
  cin >> hourVar >> discardColon >> minVar;
  while (!cin || discardColon != ':' || hourVar > 23 || hourVar < 0 || minVar > 59 || minVar < 0) {
    cout << "Invalid option! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hourVar >> discardColon >> minVar;
  }
  cout << endl;
  cin.ignore(100, '\n');
  strncpy(strTime, to_string(hourVar).c_str(), 10);
  strcat(strTime, to_string(minVar).c_str());
}