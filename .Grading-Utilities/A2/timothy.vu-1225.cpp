#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//welcome message//
void welcome(){
  cout << "Welcome to this encoding program\n" << endl;
}

//thank you message//
void thankYou(){
  cout << "\nThank you for using this encoding program" << endl;
}

//prompt the user to repeat the program or stop
char DisplayMenu(){
  char option;
  //continuously asks for the input until a valid answer is entered
  do{
    cout << "Please select an option: " << endl;
    cout << "(e) to encode" << endl;
    cout << "(q) to quit" << endl;
    cin >> option;
    cin.ignore(100, '\n');
    if(option != 'e' && option != 'q'){
      cout << "Invalid input. Please try again." << endl;
    }
  } while(option != 'e' && option != 'q');
  
  return option;
}

//reads the first name, last name, and whether the user is late or not
void ReadInput(char fName[], char lName[], bool &lateFlag){
  char late;
  int i;
  
  cout << "Enter your first name: ";
  cin.getline(fName, 20);
  //converts first name to lowercase
  for(i = 0; i < strlen(fName); ++i){
    fName[i] = tolower(fName[i]);
  }

  cout << "Enter your last name: ";
  cin.getline(lName, 20);
  //converts last name to lowercase
  for(i = 0; i < strlen(lName); ++i){
    lName[i] = tolower(lName[i]);
  }
  //validates the user's input until they type a y or n
  do{
    cout << "were you late? (y or n): ";
    cin >> late;
    //converts character to lowercase
    late = tolower(late);
    if (late == 'y'){
      lateFlag = true;
    }
    else if (late == 'n'){
      lateFlag = false;
    }
    else {
      cout << "Invalid input. Please try again." << endl;
    }
  }while (late != 'y' && late != 'n');
  cin.ignore(100, '\n');
}

//reads the studentID and file name
void ReadInput(char parsedID[], char fileName[]){
  char studentID[50];

  //takes the studentID input and saves the last 4 digits and null character
  cout << "Please enter your student ID (123-45-6789): ";
  cin.getline(studentID, 50);
  strncpy(parsedID, studentID + 7, 5);

  cout << "Please enter the file name (prog.cpp): ";
  cin.getline(fileName, 50);
}

//reads 2 integers and converts them to a single string
void ReadTime(char strTime[]){
  int hour = 0;
  int min = 0;
  char discard;

  //validates the hour and minutes inside 24hr
  do {
    cout << "Please enter the current time (24:00): ";
    cin >> hour >> discard >> min;
    if((hour < 24) && (hour > 0) && (min > 60) && (min < 0)){
      cout << "ERROR. Input is not possible in 24:00 format";
    }
  } while ((hour > 24) && (hour < 0) && (min > 60) && (min < 0));

  //input must contain ':'
  while(!cin || discard != ':'){
    cout << "Invalid input! Please try again!!" << endl;
    cin >> hour >> discard >> min;
  }
  cin.ignore(100,'\n');
  strcpy(strTime, to_string(hour).c_str());
  strcat(strTime, to_string(min).c_str());
  if(min == 0){
    strcat(strTime, "0");
  }
}

//declares and calls information to create a single char array
void encode(){
  char encodeFileName[200];
  char firstName[20];
  char lastName[20];
  bool isLate;
  char studentID[50];
  char lastPart[50];
  char timeString[5];

  ReadInput(firstName, lastName, isLate);
  ReadInput(studentID, lastPart);
  ReadTime(timeString);
  
  strcpy(encodeFileName, lastName);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, firstName);
  strcat(encodeFileName, "_");
  if (isLate == true){
    strcat(encodeFileName, "LATE_");
  }
  strcat(encodeFileName, studentID);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, timeString);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, lastPart);
  
  cout << encodeFileName << "\n" << endl;
}

//loops and calls menu and prompt functions until asked to stop
int main() {
  
  welcome();

  while(DisplayMenu() != 'q'){
    encode();
  }
  
  thankYou();
  
  return 0;
}