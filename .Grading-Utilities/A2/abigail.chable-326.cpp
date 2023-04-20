/******************************************************************************
# Author:           Abby Chable
# Lab:              Assignment 2
# Date:             April 13, 2023
# Description:      This program is a basic text encoder
# Input:            userInput, fName, lName, yesNo, stdID, fileName, hour, discard, min
# Output:           encodeFileName
# Sources:          zybooks, assignment 2 instructions
#******************************************************************************/
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//function prototypes
void welcome();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);
void toLowerCase(char name[]);

//constant variable
const int MAXCHAR = 20;

//main function
int main() {
  char fileName[MAXCHAR * 5];
  welcome();
  while(displayMenu() != 'q'){
    encode(fileName);
  }
  return 0;
}

//welcome header
void welcome(){
  cout << "Welcome to my fileName encoding program!\n\n";
}

//display menu
char displayMenu(){
  
  char userInput = ' ';
  bool validInput = false;

  //prompting and validating user input
  while(!validInput){
    cout << "Please pick an option below:\n\n";
    cout << "(e)Encode a file name\n";
    cout << "(q)quit\n";
    cout << "\n>> ";
    cin >> userInput;
    userInput = tolower(userInput);
    if(userInput == 'q'){
      cout << "\nThank you for using my fileName generator!";
      validInput = true;
    }
    else if(userInput == 'e'){
      validInput = true;
    }
    else{
      cout << "Invalid Choice\n";
    }
  }
  return userInput;
  }

//encoding the file
void encode(char encodeFileName[]){
  char firstName[MAXCHAR];
  char lastName[MAXCHAR];
  char parID[MAXCHAR];
  char nameFile[MAXCHAR];
  char time[MAXCHAR];
  bool flag = false;
  //calling functions
  readInput(firstName, lastName, flag);
  readInput(parID, nameFile);
  readTime(time);
  //creating file name
  strncpy(encodeFileName, lastName, strlen(lastName));
  strcat(encodeFileName, "_");
  strcat(encodeFileName, firstName);
  strcat(encodeFileName, "_");

  // late condition
  if(flag != true){
    strcat(encodeFileName, "LATE_");
  }
  //creating file name
  strcat(encodeFileName, parID);
  strcat(encodeFileName,"_");
  strcat(encodeFileName, time);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, nameFile);
  cout << "\nYour encoded file name is: " << encodeFileName << "\n\n";
  
}

//overloaded function for reading input
void readInput(char fName[], char lName[], bool &lateFlag){
  char yesNo = ' ';
  bool validationFlag = false;
  cout << "\nEnter your first name: ";
  cin >> fName;
  toLowerCase(fName);
  cout << "\nEnter your last name: ";
  cin >> lName;
  toLowerCase(lName);
  
  //data validation
  while(!validationFlag){
    cout << "\nWas your assignment late(y/n): ";
    cin >> yesNo;
    yesNo = tolower(yesNo);
    if(yesNo == 'y'){
      lateFlag = false;
      validationFlag = true;
    }
    else if (yesNo == 'n'){
      lateFlag = true;
      validationFlag = true;
    }
    else{
      cout << "Invalid Input. ";
      validationFlag = false;
    }
  }
}
//overloaded function for more input
void readInput(char parsedID[], char fileName[]){
  char stdID[MAXCHAR];
  cout << "\nEnter your Student-ID (format: 222-22-2222): ";
  cin >> stdID;
  strncpy(parsedID, stdID + 7, 4);
  cout << "\nEnter the file name: ";
  cin >> fileName;
}

//reading time
void readTime(char strTime[]){
  int hour = 0, min = 0;
  char discard;
  cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm):";
  cin >> hour >> discard >> min;
  //validating input
   while((!cin) || (discard != ':') || (hour < 0 || hour > 24)|| (min < 0 || min > 60))
  {
    cout << "Invalid input! Please try again: ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> min;
  }   
  cin.ignore(100,'\n');
  strncpy(strTime, to_string(hour).c_str(),10);
  strcat(strTime, to_string(min).c_str());
  
}
//function to change input to lowercase
void toLowerCase(char name[]){
  for(int i = 0; i < strlen(name); i++){
    name[i] = tolower(name[i]);
  }
}