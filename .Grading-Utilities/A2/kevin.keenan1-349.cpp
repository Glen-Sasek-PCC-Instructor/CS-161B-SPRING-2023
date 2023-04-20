#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

const int MAX_CHAR = 50;

void welcome();
char displayMenu();
void encode(char encodedFileName[]);
void readInput(char fName[], char lName[], bool lastFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char time[]);

int main() {
  char userInput;
  char encodedFileName[MAX_CHAR];

  welcome();

  userInput = displayMenu();

  while ((userInput != 'e') && (userInput != 'q')) {
    cout << "Invalid input. Please try again: ";
    userInput = displayMenu();
  }
  while (userInput == 'e') {
    encode(encodedFileName);
    cout << "\n";
    cout << "Your encoded file name is: " << encodedFileName << endl << endl;
    userInput = displayMenu();
  }

  cout << endl << "Thank you for using my fileName generator!" << endl;
}

void welcome() {
  cout << "Welcome to my fileName program!" << endl << endl;
}

char displayMenu() {
  char userChoice;

  cout << "Please pick an option from below: " << endl;
  cout << "(e) Encode a file name" << endl;
  cout << "(q) Quit" << endl;

  cin >> userChoice;
  userChoice = tolower(userChoice);

  /* if (!(userChoice == 'e') && !(userChoice == 'q')) {
    cout << "Invalid option! Please try again: ";
    cin >> userChoice;
  } */
  return userChoice;
}

void encode(char encodedFileName[]) {
  char fName[MAX_CHAR];
  char lName[MAX_CHAR];
  char parsedID[MAX_CHAR];
  char fileName[MAX_CHAR];
  char strTime[MAX_CHAR];
  bool lateFlag;

  readInput(fName, lName, lateFlag);
  readInput(parsedID, fileName);
  readTime(strTime);

  strcpy(encodedFileName, lName);
  //strcat(encodedFileName, "_");
  strcat(encodedFileName, fName);
  //strcat(encodedFileName, "_");

  if (lateFlag == true) {
    strcat(encodedFileName, "LATE_");
  }
  //strcat(encodedFileName, "_");
  strcat(encodedFileName, parsedID);
  strcat(encodedFileName, "_");
  strcat(encodedFileName, strTime);
  strcat(encodedFileName, "_");
  strcat(encodedFileName, fileName);
}

void readInput(char fName[], char lName[], bool lateFlag) {
  char lateInput;

  cout << endl << "Enter your last name: ";
  cin.getline(lName, MAX_CHAR);
  cin.get();
  strcat(lName, "_");
  
  cout << endl << "Enter your first name: ";
  cin.getline(fName, MAX_CHAR);
  cin.get();
  cin.clear();
  cin.ignore(100, '\n');
  strcat(fName, "_");
  
  cout << endl << "Was your assignment Late (y/n)?: ";
  cin >> lateInput;
  lateInput = tolower(lateInput);
  
  while (!(lateInput == 'y') && !(lateInput == 'n')) {
    cout << "Invalid input. Please try again: ";
    cin >> lateInput;
  }

  if (lateInput == 'y') {
    lateFlag = true;
  }
  else if (lateInput == 'n') {
    lateFlag = false;
  }
  cin.clear();
  cin.ignore(100, '\n');
}

void readInput(char parsedID[], char fileName[]) {
  char studentID[MAX_CHAR];

  cout << endl << "Enter your Student-ID (Format 222-22-2222): ";
  cin.getline(studentID, MAX_CHAR);
  //cin.get();
  
  cout <<endl << "Enter the file name: ";
  cin.getline(fileName, MAX_CHAR);
  //cin.get();
  strncpy(parsedID, studentID + 7, 4);
}

void readTime(char strTime[]) {
  int hour = 0;
  int minute = 0;
  char discard;

  cout << endl;
  cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
  cin >> hour >> discard >> minute;

  while ((!cin || discard != ':') || (hour > 24 && hour < 0) || (minute > 60 && minute < 0)) {
    cout << "Invalid input! Please try again: " << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> minute;
  }

  cin.ignore(100,'\n');
  strncpy(strTime, to_string(hour).c_str(),10);
  strcat(strTime, to_string(minute).c_str());
}