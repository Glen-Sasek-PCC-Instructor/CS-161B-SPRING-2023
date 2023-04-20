//*****************************************************************************
// Author: Sydney Montelongo  
// Assignment: Assignment 2
// Date: April 5th, 2023
// Description: This program will read from the user the student's first and last name, whether or not the assignment was late, their student ID, the file name, and the time submitted. It will use this information to generate an encoded file name. It will also inlcude data validation and a choice menu that allows the user to use the program multiple times.
// Input: char userChoice, char array fName, char array lname, char lateResponse char array studentID, char array fileName, char array time
// Output: char array encodeFileName
// Sources:
//*****************************************************************************

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAXCHAR = 50;

void welcome();

char displayMenu();

void encode(char encodeFileName[]); 

void readInput(char fName[], char lName[], bool &lateFlag);

void readInput (char parsedID[], char fileName[]);

void readTime(char strTime[]);

void makeLowercase(char userString[]);



int main() {
  char userChoice;
  char encodeFileName[MAXCHAR] = "";
  
  welcome();
  userChoice = displayMenu();
  cout << endl;
  while (userChoice != 'q') {
    encode(encodeFileName);
    userChoice = displayMenu();
  }
  cout << endl;
  cout << "Thank you for using my fileName generator!" << endl;
  
	return 0;
}

void welcome() {
  cout << "Welcome to my fileName encoding program!" << endl;
  cout << endl;
}

char displayMenu() {
  char userChoice;

  cout << "Please pick an option below: " << endl;
  cout << " (e)Encode a file name" << endl;
  cout << " (q)quit" << endl;
  cout << ">>";

  cin >> userChoice;
  userChoice = tolower(userChoice);
  
  while(userChoice != 'e' && userChoice != 'q')
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> userChoice;
  }
  return userChoice;
}

void encode(char encodeFileName[]) {
  char fName[MAXCHAR] = "";
  char lName[MAXCHAR] = "";
  bool lateFlag;
  char parsedID[MAXCHAR] = "";
  char fileName[MAXCHAR] = "";
  char strTime[MAXCHAR] = "";

  cout << "This program will ask you a few questions and generate an encoded fileNmae based on your answers." << endl;
  cout << endl;
  
  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime( strTime);

  strcpy(encodeFileName, lName);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fName);
  strcat(encodeFileName, "_");
  if (lateFlag) {
    strcat(encodeFileName, "LATE");
    strcat(encodeFileName, "_");
  }
  strcat(encodeFileName, parsedID);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, strTime);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fileName);

  cout << endl;
  cout << "Your encoded file name is: " << encodeFileName << endl;
  cout << endl;
  }

void readInput(char fName[], char lName[], bool &lateFlag) {
  char lateResponse;
  
  cout << "Enter your last name: ";
  cin >> lName;
  makeLowercase(lName);
  cout << endl;
  cout << "Enter your first name: ";
  cin >> fName;
  makeLowercase(fName);
  cout << endl;
  cout << "Was your assignment Late (y/n)? ";
  cin >> lateResponse;
  lateResponse = tolower(lateResponse);

  while (lateResponse != 'y' && lateResponse != 'n') {
    cout << "Invalid response, please try again!" << endl;
    cin >> lateResponse;
    lateResponse = tolower(lateResponse);
  }
  if (lateResponse == 'y') {
    lateFlag = true;
  }
  else if (lateResponse == 'n') {
    lateFlag = false;
  }
  cout << endl;
}

void readInput (char parsedID[], char fileName[]) {
  char studentID[MAXCHAR] = "";

  cout << "Enter your Student-ID (format: 222-22-2222): ";
  cin >> studentID;
  strncpy(parsedID, studentID + 7, 4);
  cout << endl;

  cout << "Enter the file name: ";
  cin >> fileName;
  cout << endl;
}

void readTime(char strTime[]) {
  int hour = 0;
  int min = 0;
  char discard;

  cout << "Enter the time submitted (military time- ex: 18:24 for 6:24 pm): ";
  cin >> hour >> discard >> min;

  while (!cin || discard != ':'|| hour < 0 || hour > 24 || min < 0 || min > 59) {
    cout << "Invalid input! Please try again!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> min;
  }
  cin.ignore(100, '\n'); 
  strncpy(strTime, to_string(hour).c_str(),10);
  strcat(strTime, to_string(min).c_str());
}

void makeLowercase(char userString[]) {
  int length = strlen(userString);

  for (int i = 0; i < length; i++) {
    userString[i] =       tolower(userString[i]);
  }
}