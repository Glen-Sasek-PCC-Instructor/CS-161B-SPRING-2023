//******************************************************************************
//# Author:           Megan Rothstein
//# Assignment:       Assingment 2
//# Date:             April 16th, 2023
//# Description: This program will create a file name for submitted documents based on the user’s name, time of submission, student I.D. number and whether the file was submitted late. 
//# Input: char encodeQuit, fName, lName, parsedID, fileName, strTime
 // bool lateFlag
//# Output: char encodeQuit, fName, lName, parsedID, fileName, strTime
 // bool lateFlag
// # Sources: Assingment 2 prompt, stackexchange for sprintf command for seperating numbers in time
//******************************************************************************

#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

// first listing of functions to be implemented after main
void welcome();
void goodbye();
char displayMenu();
void encode();
void readInput(char fName[], char lName[], bool &lateFlag);
void readFile(char parsedID[], char fileName[]);
void readTime(char strTime[]);

// main functions displaying output of calculated values for tests and
// reiterating user's input
int main() {
char userOption, parsedID[12], fileName[100], strTime[7], lastFourDigits[5];
bool lateFlag;

welcome();                        // welcome function called
userOption = displayMenu();
if (userOption == 'e')
  {
    encode ();
  }
displayMenu();
goodbye();                        // goodbye function called
  return 0;
}
// welcome function outputs the title and instructions for the program
void welcome() {
  cout << "Welcome to the fileName generator program!" << endl;
}
char displayMenu(){
  char encodeQuit;
  cout << "Please pick an option below:" << endl;
  cout << "(e)Encode a file name" << endl;
  cout << "(q)quit" << endl;
  cin >> encodeQuit;
  cin.ignore();
    // check which option was selected
  if (encodeQuit == 'e') {
    cout << "You selected encode a file name" << endl;
  } else if (encodeQuit == 'q') {
    cout << "You selected quit" << endl;
    return 0;
  } 
  else { cout << "Please select e or q and try again." << endl;
       cout << "Please pick an option below:" << endl;
  cout << "(e)Encode a file name" << endl;
  cout << "(q)quit" << endl;
  cin >> encodeQuit;
        if (encodeQuit != 'e' || encodeQuit != 'q') { cout << "Please select e or q and try again." << endl; }
  cin.ignore();}
  return encodeQuit;
}
void encode(){
  char fName[20], lName[20], lastFourDigits[5], fileName[100], strTime[7], parsedID[20];
  bool lateFlag;
  readInput(fName, lName, lateFlag);
  cin.ignore(1000, '\n');
  cin.clear();
  readFile(parsedID, fileName);
  readTime(strTime);
   // Creat and print the final file name
   char finalFileName[100];
   if (lateFlag == 'n'){
cout << "Final file name: " << lName << "_" << fName << "_" << lastFourDigits << "_" << strTime << "_" << fileName << ".c" << endl;}
  if (lateFlag = 'y'){ cout << "Final file name: " << lName << "_" << fName << "_" << lastFourDigits << "_" << strTime << "_" << "LATE" << "_" << fileName << ".c" << endl;}
}

void readInput(char fName[], char lName[], bool &lateFlag) {
  cout << "Enter your first name:" << endl;
  cin.getline(fName, 20);
  for (int i = 0; i < strlen(fName); i++) {
  if (isupper(fName[i])) {
    fName[i] = tolower(fName[i]);
  }}
  cout << "Enter your last name:" << endl;
  cin.getline(lName, 20); 
  for (int i = 0; i < strlen(lName); i++) {
  if (isupper(lName[i])) {
    lName[i] = tolower(lName[i]);
  }}
  cout << "Did you submit the file late? (y/n):" << endl;
  cin >> lateFlag;
  cin.ignore(1000, '\n'); 
  cin.clear();

  // confirm input to user
  cout << "Your name is " << fName << " " << lName << "." << endl;
  if (lateFlag) {
    cout << "You submitted the file late." << endl;
  } else {
    cout << "You submitted the file on time." << endl;
  }
  cin.ignore();
  return lateFlag;
}

void readFile(char parsedID[], char fileName[]) {
 
  char lastFourDigits[5]; 
  cout << "Enter your Student-ID (format: 222-22-2222): " << endl;
  cin.ignore();
  cin.getline(parsedID, 12);
 strncpy(lastFourDigits, parsedID + 6, 4); 
  lastFourDigits[4] = '\0';
  cout << "The last four digits will be used in your file name: " << lastFourDigits << endl;
    // prompt for fileName
  cout << "Enter a file name: " << endl;
  cin.getline(fileName, 10);
  cout << "Your file name is: " << fileName << endl;
  fileName = lastFourDigits;
}

void readTime(char strTime[]) {
  cin.ignore(1000, '\n'); 
 // cin.clear();
  int hour = 0, min = 0;
  char discard;
  cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
  cin >> hour >> discard >> min;
  while(!cin || discard != ':')
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> min;
  }   
  cin.ignore(100,'\n');
  strTime[7];
  sprintf(strTime, "%02d%02d", hour, min); 
  
 cout << "You entered: " << strTime << endl;
}


void goodbye(){ cout << "Thank you for using this program." << endl;}