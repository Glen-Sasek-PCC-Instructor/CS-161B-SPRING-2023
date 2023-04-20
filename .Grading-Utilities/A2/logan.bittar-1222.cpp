//*****************************************************************************
// Author: Logan Bittar
// Assignment: Assignment 2
// Date: 4/15/23
// Description: This program will encode a file based on user inputs.
// Input: char fName[], lName[], strTime[], fileName[], parsedID[]
//        bool lateFlag  
// Output: char encodeFileName[]
// Sources:
//*****************************************************************************

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void welcome();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void toLowerCase(char fName[], char lName[]);
void readTime(char strTime[]);

const int MAXTIMEHOURS = 24;
const int MAXTIMEMINUTES = 60;

int main() {
  char display, firstName[50], lastName[50], parsedID[50], fileName[50], strTime[50], encodeFileName[50];
  bool late;
  
  welcome();
  display = displayMenu();

  if (display == 'q') {
    cout << "Thank you for using my fileName generator!" << endl;
  } else if (display == 'e') {
    cout << "\nThis program will ask you a few questions and generate an encoded fileName based on your answers." << endl;
    encode(encodeFileName);
  } 

}

void welcome() {
  cout << "\nWelcome to my fileName encoding program!!" << endl;
  cout << "Please pick an option below:" << endl;
}

char displayMenu() {
  char display;
  cout << " (e) Encode a file name" << endl;
  cout << " (q) quit" << endl;
  cin >> display;

  while (display != 'q' && display != 'e') {
    cout << "Invalid input! Try again!" << endl;
    display = displayMenu();
  }

  return display;
}

void readInput(char fName[], char lName[], bool &lateFlag) {
  char late;
  
  cout << "\nEnter your last name: ";
  cin.ignore(50, '\n');
  cin.getline(lName, 50);

  cout << "\nEnter your first name: ";
  cin.getline(fName, 50);

  cout << "\nWas your assignment Late (y/n)? ";
  cin >> late;

  if (late == 'y' || late == 'Y') {
    lateFlag = true;
  } else if (late == 'n' || late == 'N') {
    lateFlag = false;
  }

  while (late != 'y' && late != 'Y' && late != 'n' && late != 'N') {
    cout << "Invalid input! Try again!" << endl;
    cout << "\nWas your assignment Late (y/n)? ";
    cin >> late;
  }
}


void toLowerCase(char fName[], char lName[]) {
  for (int i = 0; fName[i] != '\0'; ++i) {
      fName[i] = tolower(fName[i]);
  }

  for (int i = 0; lName[i] != '\0'; ++i) {
      lName[i] = tolower(lName[i]);
  }
}

void readInput(char parsedID[], char fileName[]) {
  char stdID[50];
  
  cout << "\nEnter your Student-ID (format: 222-22-2222): ";
  cin.ignore(50, '\n');
  cin.getline(stdID, 50);
  strncpy(parsedID, stdID + 7, 4);

  cout << "\nEnter the file name: ";
  cin.getline(fileName, 50);
}

void readTime(char strTime[]) {
  int hour = 0, min = 0;
  char discard;
  
  cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
  cin >> hour >> discard >> min;

  while(!cin || discard != ':')
  {
    cout << "Invalid input! Try again!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> min;
  }

  strncpy(strTime, to_string(hour).c_str(),10);
  strcat(strTime, to_string(min).c_str());
}

void encode(char encodeFileName[]) {
  char display, firstName[50], lastName[50], parsedID[50], fileName[50], strTime[50];
  bool late;

  //get first name, last name, and if assignment late
  readInput(firstName, lastName, late);
  //change name to lower case
  toLowerCase(firstName, lastName);
  //get student ID and file name
  readInput(parsedID, fileName);
  //get time
  readTime(strTime);
  
  if (late == true) {
    strncpy(encodeFileName, lastName, strlen(lastName));
    strcat(encodeFileName, "_");
    strcat(encodeFileName, firstName);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, "LATE");
    strcat(encodeFileName, "_");
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, strTime);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
    cout << "\nYour encoded file name is: " << encodeFileName << endl;
    cout << "Thank you for using my fileName generator!" << endl;
  } else if (late == false) {
    strncpy(encodeFileName, lastName, strlen(lastName));
    strcat(encodeFileName, "_");
    strcat(encodeFileName, firstName);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, strTime);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
    cout << "\nYour encoded file name is: " << encodeFileName << endl;
    cout << "Thank you for using my fileName generator!" << endl;
  }
}