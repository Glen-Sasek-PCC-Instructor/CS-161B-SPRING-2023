/*******************************************************************************
# Author:           Nonso. A
# Lab:              Assignment #2
# Date:             April 16, 2023
# Description:      This program encodes the student's filename using the full name of said student, and their student ID, assignment title/name, (late or early assignment), and timeframe(military time).
# Input:            const (int), char,
# Output:           char encode
# Sources:          Zybooks
#******************************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//DECALRE const intt, char

const int MAX = 50; 
const char LATE[MAX] = "LATE";
const char UNDER_SCORE[] = "_";

//prototypes 

void welcome();

void displayMenu();

char readOption();

void readInput(char firstName[], char lastName[], bool &lateFlag);

void readInput(char parsedID[], char fileName[]);

void readTime(char militaryTime[]);

void encode(char encodeFileName[]);


int main() {

  //variables 


  char encodeFileName[MAX] = {0};
  
  char option;

  welcome();
  displayMenu();
  option = readOption();
  
  while(option != 'q' && option == 'e') {
    encode(encodeFileName);
      cout << "\nYour encoded file name is: " << encodeFileName << endl;

    displayMenu();
    option = readOption();
  }

  cout << "\nThank you for using my file name generator!" << endl;

  
  return 0;
}

// functions

//Name: welcome()
//Desc: Displays welcome message/instructions
//input: None
//output: None
//return: None
void welcome() {
  cout << "\nWelcome to my fileName encoding program!!" << endl;
}

//Name: displayMenu()
//Desc: Displays menu options
//input: None
//output: none
//return: None

void displayMenu(){
    cout << "\nPlease pick an option from below:" << endl;
    cout << "(e)ncode" << endl;
    cout << "(q)uit" << endl;
    cout << ">> ";
  }

//Name: readOption()
//Desc: Takes in user input for menu options
//input: option
//output: Invalid option message if invalid
//return: option

char readOption() {
  char option = 0; 
  cin >> option;

  while(tolower(option) != 'e' && tolower(option) != 'q') {
    cout <<"Invalid option, try again!" << endl; 
    displayMenu();
    cin >> option;
  }
  return tolower(option);
}
//Name: readInput(char firstName[], char lastName[], bool &lateFlag)
//Desc: Takes user input for last name, first name, and input for if assignment was on time or not
//input: lastName, firstName, lateYN
//output: Invalid option message if invalid input 
//return: none

void readInput(char firstName[], char lastName[], bool &lateFlag) {
  char lateYN = 0; 
  
  cout << "\nEnter your last name: ";
  cin >> lastName;
  int i = 0;
  for(i = 0; i < strlen(lastName); i++){
      lastName[i] = tolower(lastName[i]);
    }
  
  cout << "\nEnter your first name: ";
  cin >> firstName;

  for(i = 0; i < strlen(firstName); i++){
      firstName[i] = tolower(firstName[i]);
    }
  
  
  //tolower(char firstName); FIXME 
  
  cout << "\nWas your assignment late (y/n)? ";
  cin >> lateYN;
  lateYN = tolower(lateYN);
  while(tolower(lateYN != 'y' && tolower(lateYN) != 'n')) {
    cout << "Invalid option, please try again" << endl;
    cout << "\n Was your assignment late (y/n)? ";
    cin >> lateYN;
  }
  if(lateYN == 'y') {
    lateFlag = true; 
  }
  
}

//Name: void readInput(char parsedID[], char fileName[])
//Desc: Calculates user input for student ID and for file name
//input: studentID, fileName
//output: none
//return: none

void readInput(char parsedID[], char fileName[]) {
  char studentID[MAX] = {0};
  cout << "\nEnter your Student-ID (format: 222-22-2222): ";
  cin >> studentID;
  
  strncpy(parsedID, studentID + 7, 4); 

  cin.ignore();
  cout << "\nEnter the file name: ";
  cin >> fileName;
 
}

//Name: void readTime(char militaryTime[])
//Desc: Input users miltary time
//input: hours, min
//output: none
//return: none

void readTime(char militaryTime[]) {
  int hours = 0; 
  int min = 0;
  char discard;

  cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): "; //add input val
  cin >> hours >> discard >> min;

  while(!cin || hours > 24 || hours < 0) {
    cout << "\nInvalid input, please try again!";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hours >> discard >> min;
  }

  while(!cin || min > 60 || min < 0) {
    cout << "\nInvalid input, please try again!";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hours >> discard >> min;
  }

  while(!cin || discard != ':') {
    cout << "\nInvalid input, please try again!";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hours >> discard >> min;
  }
  cin.ignore(100, '\n');
  strncpy(militaryTime, to_string(hours).c_str(), 10);
  strcat(militaryTime, to_string(min).c_str());
}

//Name: void encode(char encodeFileName[]) 
//Desc: Display message and compiles all function values needed to create final encodedFileName
//input: none
//output: encodedFileName
//return: none

void encode(char encodeFileName[]) {
char firstName[MAX] = {0};
char lastName[MAX] = {0};
bool lateFlag;
char parsedID[MAX] = {0};
char fileName[MAX] = {0};
char militaryTime[MAX] = {0};

  
cout << "\nThis program will ask you a few questions and generate an encoded fileName based on your answers." << endl;
  
readInput(firstName, lastName, lateFlag);
strcpy(encodeFileName, lastName);
strcat(encodeFileName, UNDER_SCORE);
strcat(encodeFileName, firstName);
strcat(encodeFileName, UNDER_SCORE);
  
if(lateFlag == true) {
  strcat(encodeFileName, LATE);
  strcat(encodeFileName, UNDER_SCORE);
}
  
readInput(parsedID, fileName);
strcat(encodeFileName, parsedID);
strcat(encodeFileName, UNDER_SCORE);


readTime(militaryTime);
strcat(encodeFileName, militaryTime);
strcat(encodeFileName, UNDER_SCORE);
  
strcat(encodeFileName, fileName);

  
}






