/******************************************************************************
# Author:           Sebastian Echeverria
# Lab:              Assignment #2
# Date:             April 11, 2023
# Description:      This program will allow for PCC to encode and build the file name for D2L. You should ask the user at the beginning if they are building the name of the file (encoding it) or if the program wants to quit.  Then, the user will need to enter in information to allow the program to build the encoded file name or quit.

# Input:        char lName, fName, parsedID, fileName, strTime and bool lateFlag
# Output:         char encodedFileName
# Sources:        Zybook
#******************************************************************************/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void welcome();
char displayMenu();
void encode();
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);


int main() {
  
  welcome();
  char option = displayMenu();
  while (option != 'q') {
    option = displayMenu();
  }
  
  
  return 0; 
}

void welcome() {
  cout << "Welcome to my fileName encoding program!!" << endl;
}

char displayMenu() {
  char option;
  cout << "\nPlease pick an option below:" << endl;
  cout << "(e)Encode a file name" << endl;
  cout << "(q)quit" << endl;
  cout << ">>";
  cin >> option;
  while ((option != 'e') && (option != 'q')) {
    cout << "Invalid option! Please try again!!" << endl;
    cout << "Please pick an option below:" << endl;
    cout << "(e)Encode a file name" << endl;
    cout << "(q)quit" << endl;
    cout << ">>";
    cin >> option;
  }
  if (option == 'e') {
    encode();
  }
  else {
    cout << "\nThank you for using my fileName generator" << endl;
  }
  return option;
}
void readInput(char fName[], char lName[], bool &lateFlag){
  int i;
  char lateOrNot;
  cout << "Enter your last name: ";
  cin >> lName;
  cout << "\nEnter your first name: ";
  cin >> fName;
  cout << "\nWas your assignment Late (y/n)? ";
  cin >> lateOrNot;
  while(lateOrNot != 'y' && lateOrNot != 'Y' && lateOrNot != 'n' && lateOrNot != 'N') {
    cout << "Invalid input! Please try again!!" << endl;
    cout << "Was your assignment Late (y/n)? ";
    cin >> lateOrNot;
  }
  if (lateOrNot == 'y' || lateOrNot == 'Y') {
    lateFlag = true;
  }
  else if (lateOrNot == 'n' || lateOrNot == 'N') {
    lateFlag = false;
  }
  
  for (i = 0; i < strlen(lName); i++) {
    lName[i] = tolower(lName[i]);
  }
  for (i = 0; i < strlen(fName); i++) {
    fName[i] = tolower(fName[i]);
  }
}

void readInput(char parsedID[], char fileName[]) {
  char stdID[51];
  cout << "\nEnter your Student-ID (format: 222-22-2222): ";
  cin >> stdID;
  cout << "\nEnter the file name: ";
  cin >> fileName;
  strncpy(parsedID, stdID + 7, 4);
}

void readTime(char strTime[]){
  int hour = 0, min = 0;
  char discard;
  cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
  cin >> hour >> discard >> min;
  while(!cin || discard != ':') {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hour >> discard >> min;
  }
  cin.ignore(100,'\n');
  strncpy(strTime, to_string(hour).c_str(),10);
  strcat(strTime, to_string(min).c_str());
}

void encode() {
  char lName[51];
  char fName[51];
  char lateOrNot;
  bool lateFlag;
  char parsedID[51];
  char fileName[51];
  char strTime[51];
  char encodeFileName[51];
  
  cout << "This program will ask you a few questions and generate an encoded fileName based on your answers.\n" << endl;
  
  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime(strTime);

  if(lateFlag == true) {
    strcat(lName, "_");
    strcpy(encodeFileName, lName);
    strcat(encodeFileName, fName);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, "LATE");
    strcat(encodeFileName, "_");
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, strTime);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
    cout << "Your encoded file name is: " << encodeFileName << endl;
  }
  else if(lateFlag == false) {
    strcat(lName, "_");
    strcpy(encodeFileName, lName);
    strcat(encodeFileName, fName);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, strTime);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
    cout << "Your encoded file name is: " << encodeFileName << endl;
    
  }
  
}