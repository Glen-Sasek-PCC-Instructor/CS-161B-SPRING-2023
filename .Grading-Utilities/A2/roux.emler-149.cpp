/****************************************************************
Name:         Roux Emler
Date:         4/16/23 
Assingment:   02
Description:  This program takes information about the user and the                 name of a file. This information is than used to encode               a more descriptive file name which is then output to                  the user.
Inputs:       The users name and id, the time submitted, whether it                 was late or not, and the file name.
Outputs:      The encoded file name.
Sources:  
https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/10
https://docs.google.com/document/d/1PGPeT1WWj1Gcxh_8TdMjbiR75LlhEUtsZiQ3vIIbl1w/edit#
*****************************************************************/

#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

const int MAX_NAME_LENGTH = 31;
const int MAX_PARSEDID_LENGTH = 5;
const int MAX_ID_LENGTH = 12;
const int MAX_FILENAME_LENGTH = 31;
const int MAX_TIME_LENGTH = 6;
const int MAX_ENCODED_LENGTH = 117;
const char FILE_SPACER[3] = "_\0";
const char INVALID_INPUT[37] = "Invalid option! Please try again!!\n\0";

void welcome();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool& lateFlag);
void readInput(char parsedID[], char fileName[]);
void makeLower(char name[]);
void readTime(char strTime[]);

int main() {
  char userChoice;
  char encodeFileName[MAX_ENCODED_LENGTH] = {0};
  bool quit = false;

  welcome();
  while (!quit) {
    userChoice = displayMenu();
    if (userChoice == 'q') {
      quit = true;
      continue;
    }

    encode(encodeFileName);
    
    cout << "Your encoded file name is: " << encodeFileName << endl;
    
  }

  cout << "Thank you for using my fileName generator!\n";
  return 1;
}

void welcome() {
  cout << "Welcome to my fileName encoding program!!\n\n";
}

char displayMenu() {
  char userChoice = ' ';
   
  while (userChoice != 'q' && userChoice != 'e') {
    
    cout << "Please pick and option below:\n"
         << "(e) Encode a file name\n"
         << "(q) quit\n"
         << ">> ";
  
    cin >> userChoice;
    userChoice = tolower(userChoice);
    
    if (!cin || (userChoice != 'q' && userChoice != 'e')) {
      cout << INVALID_INPUT;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return userChoice;
}

void encode(char encodeFileName[]) {
  char fName[MAX_NAME_LENGTH];
  char lName[MAX_NAME_LENGTH];
  bool lateFlag;
  char parsedID[MAX_PARSEDID_LENGTH];
  char fileName[MAX_FILENAME_LENGTH];
  char strTime[MAX_TIME_LENGTH];

  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime(strTime);

  strcpy(encodeFileName, lName);
  strcat(encodeFileName, FILE_SPACER);
  strcat(encodeFileName, fName);
  strcat(encodeFileName, FILE_SPACER);

  if (lateFlag) {
    strcat(encodeFileName, "LATE");
    strcat(encodeFileName, FILE_SPACER);
  }

  strcat(encodeFileName, parsedID);
  strcat(encodeFileName, FILE_SPACER);
  strcat(encodeFileName, strTime);
  strcat(encodeFileName, FILE_SPACER);
  strcat(encodeFileName, fileName);
}

void readInput(char fName[], char lName[], bool& lateFlag){
  char lateChar;
  cout << "Enter your last name: ";
  cin >> lName;
  makeLower(lName);
  
  cout << "Enter your first name: ";
  cin >> fName;
  makeLower(fName);

  do {
    cout << "Was your assignment Late (y/n)? ";
    cin >> lateChar;
    lateChar = tolower(lateChar);
    
    if (!cin || (lateChar != 'y' && lateChar != 'n')) {
      cout << INVALID_INPUT;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (lateChar != 'y' && lateChar != 'n');

  if (lateChar == 'y') {
    lateFlag = true;
  }
  else {
    lateFlag = false;
  }
}

void readInput(char parsedID[], char fileName[]){
  char stdID[MAX_ID_LENGTH];

  cout << "Enter your Student-ID (format: 222-22-2222): ";
  cin >> stdID;

  strncpy(parsedID, stdID + 7, 4);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  cout << "Enter the file name: ";
  cin >> fileName;
}

void readTime(char strTime[]){
  int hours;
  int mins;
  char discard;

  do {
    cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hours;
    cin >> discard;
    cin >> mins;
  
    if (!cin || discard != ':' || hours < 0 || hours >= 24 || mins < 0 || mins >= 60) {
      cout << INVALID_INPUT;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  } while (discard != ':' || hours < 0 || hours >= 24 || mins < 0 || mins >= 60);
  
  strcpy(strTime, to_string(hours).c_str());
  strcat(strTime, to_string(mins).c_str());
}


void makeLower(char name[]) {
  for (size_t i = 0; i < strlen(name); ++i){
    name[i] = tolower(name[i]);
  }
}