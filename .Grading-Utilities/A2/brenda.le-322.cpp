/******************************************************************************
# Author:           Brenda Le
# Lab:              Discussion #2
# Date:             April 13, 2023
# Description:      This program will encode a file name.
# Input:            option (e/q), last name, first name, late (y/n), studentID, file name, time
# Output:           encoded file name
# Sources:          zybooks, assignment 2 specifications
#******************************************************************************/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// function prototypes
void welcome();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);
void lowercase(char name[]);

// constant variables
const string SPACER = "\n";
const int MAXCHAR = 20;

// MAIN
int main() {
  char file[MAXCHAR * 5];
  welcome();
  while (displayMenu() == 'e')
  {
  encode(file);
  }
}

// welcome
void welcome()
{
  cout << "Welcome to my fileName encoding program!\n" << SPACER;
}

// menu
char displayMenu()
{
  char file[MAXCHAR * 5];
  char userChoice = ' ';
  bool validChoice = false;

  // validating choice
  while (!validChoice)
  {
  cout << "Please pick an option below:\n";
  cout << "(e)Encode a file name\n";
  cout << "(q)quit\n";
  cout << "\n>> ";
  cin >> userChoice;

  userChoice = tolower(userChoice);
    
     if (userChoice == 'e')
    {
      validChoice = true;
    }
    else if (userChoice == 'q')
    {
      validChoice = true;
      cout << SPACER << "Thank you for using my fileName generator!";
    }
    else
    {
      cout << "Invalid input. Please try again.\n" << SPACER;
    }
  }
  return userChoice;
}

// encoding file name
void encode(char encodeFileName[])
{
  char firstN[MAXCHAR];
  char lastN[MAXCHAR];
  char studentID[MAXCHAR];
  char time[MAXCHAR];
  char fileName[MAXCHAR];
  bool flag = false;
  // calling functions to read input
  readInput(firstN, lastN, flag);
  readInput(studentID, fileName);
  readTime(time);
  // making file name
  strncpy(encodeFileName, lastN, strlen(lastN));
  strcat(encodeFileName, "_");
  strcat(encodeFileName, firstN);
  strcat(encodeFileName, "_");

  // including late
  if(flag == false)
  {
    strcat(encodeFileName, "LATE_");
  }
  // making file name
  strcat(encodeFileName, studentID);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, time);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fileName);
  
  cout << SPACER << "Your encoded file name is: " << encodeFileName << endl << SPACER;
}

// read first/last name and late flag
void readInput(char fName[], char lName[], bool &lateFlag)
{
  char late = ' ';
  bool validFlag = false;
  
  cout << SPACER << "Enter your last name: ";
  cin >> lName;
  lowercase(lName);
  cout << SPACER << "Enter your first name: ";
  cin >> fName;
  lowercase(fName);
  // validating flag
  while (!validFlag)
  {
  cout << SPACER << "Was your assignment late (y/n)? ";
  cin >> late;
  late = tolower(late);

    if (late == 'y')
    {
      lateFlag = false;
      validFlag = true;
    }
    else if (late == 'n')
    {
      lateFlag = true;
      validFlag = true;
    }  
    else 
    {
      cout << "Invalid input. Try again.\n";
      validFlag = false;
    }
  }
}

// read ID and file name
void readInput(char parsedID[], char fileName[])
{
  char stdID[MAXCHAR];
  cout << SPACER << "Enter your Student-ID (format: 222-22-2222): ";
  cin >> stdID;
  strncpy(parsedID, stdID + 7, 4);
  cout << SPACER << "Enter the file name: ";
  cin >> fileName;
}

// read time
void readTime(char strTime[])
{
  int hour = 0, min = 0;
  char discard;
  cout << SPACER << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
  cin >> hour >> discard >> min;
  // validating time
   while(!cin || discard != ':' || (hour < 0 || hour > 24) || (min < 0 || min > 60))
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

// making name lowercase
void lowercase(char name[])
{
  for (int i = 0; i < strlen(name); i++)
  {
  name[i] = tolower(name[i]);    
  }
}
