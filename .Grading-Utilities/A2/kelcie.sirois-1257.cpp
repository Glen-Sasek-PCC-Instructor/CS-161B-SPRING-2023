/******************************************************************************
# Author:           Kelcie Sirois
# Assignment:       A02 Grade Calculator (CS161B)
# Date:             April 12th 2023
# Description:      This program will prompt for the user's assignment information 
                    and encode a file format for their submission. The program will ask for 
                    their last and first name, late assignment(y/n), student ID, submission time, and assignment name. 
# input:            fName, lName, stdID, strTime, fileName as char array. Choice, lateChoice,colon as char. hour and min as int
# Output:           encodeFileName as char array
# Sources:          Chapter 10 zybooks, assignment a02 specifications including examples for int to cstring link in assignment document.          
#******************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//constants
const int MAXTIME = 10;

// Function prototypes
void welcome();
char displayMenu();
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);
void encode(char encodeFileName[]);

int main() {
  //declare variables  
  char strTime[MAXTIME] = {0};
  char choice;
    welcome();
    do { //loop to encode another file until user quits
        choice = displayMenu();
        if (choice == 'e') {
            char encodeFileName[100];
            encode(encodeFileName);
            cout << "\nYour encoded file name is: " << encodeFileName << endl;
        }
    } while (choice != 'q');

    //Closing message
    cout << "\nThank you for using the file name encoder program!" << endl;

    //end program
    return 0;
}
//Name: welcome()
//Desc: This function displays the welcome message
//input: None
//output: none
//return: None
void welcome() {
    cout << "Welcome to the file name encoder program!" << endl;
}
//Name: displayMenu()
//Desc: This function displays the options menu for user 
//input: none
//output: message and directions as string
//return: choice as char
char displayMenu() {
    char choice;
    do {
        cout << "\nPlease select an option:" << endl;
        cout << "(e)Encode a file name" << endl;
        cout << "(q)Quit the program" << endl;
        cin >> choice;
        choice = tolower(choice);
    } while (choice != 'e' && choice != 'q');

    return choice;
}
//Name: readInput(fName[], lName[], &lateflag)
/*Desc: This function reads the last and first name of user, 
converts to lowercase, and reads if file was late */
//input: fName and lName as char array and lateflag as bool by reference
//output: updated fName and lName as char array and updated lateflag as bool
//return: None
void readInput(char fName[], char lName[], bool &lateFlag) {
    cout << "\nThis program will ask you a few questions to generate an" <<
    " encoded fileName based on your answers." << endl;
    //Read last name
    cout << "\nEnter your last name: ";
    cin >> lName;

    //Read first name
    cout << "\nEnter your first name: ";
    cin >> fName;

    //Convert name to lowercase
    for (int i = 0; fName[i] != '\0'; i++) {
        fName[i] = tolower(fName[i]);
    }
    for (int i = 0; lName[i] != '\0'; i++) {
        lName[i] = tolower(lName[i]);
    }

    //Read late flag
    char lateChoice;
    do {
        cout << "\nWas your assignment late (Y/N)? ";
        cin >> lateChoice;
        lateChoice = toupper(lateChoice);
    } while (lateChoice != 'Y' && lateChoice != 'N');

    lateFlag = (lateChoice == 'Y');
}
//Name: readInput(parsedID[], fileName[])
/*Desc: This function reads the student ID to extract last four 
numbers and file name from user  and reads the file name*/
//input: parsedID and filename as char array
//output: updated parsedID and filename as char array
//return: None
void readInput(char parsedID[], char fileName[]) {
    // Read student ID
    char stdID[12];
    cout << "\nEnter your student ID (format: 222-22-2222): ";
    cin >> stdID;
    // Extract last 4 digits of student ID
    strncpy(parsedID, stdID + 7, 4);
    parsedID[4] = '\0';

    // Read filename
    cout << "\nEnter the file name: ";
    cin >> fileName;
}
//Name: readTime(strTime[])
/*Desc: This function prompts for the submission time in HH:MM format, 
validates input, converts HH and MM into string then to cstring */
//input: strTime as char array
//output: updated format of strTime as char array 
//return: None
void readTime(char strTime[]) {
    int hour = 0, min = 0;
    char colon;
    cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hour >> colon >> min;
  
    while (hour < 0 || hour > 24 || min < 0 || min > 60 || colon != ':'){
      cout << "Invalid input! Enter time in the HH:MM format: " << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> hour >> colon >> min;
    }
    //ignore newline
    cin.ignore(100,'\n');
    //convert hour from int to string then to cstring and copy to strTime
    strncpy(strTime, to_string(hour).c_str(),10);
    //convert min from int to string and then cstring and concatenate to strTime
    strcat(strTime, to_string(min).c_str());
    
}
//Name: encode(encodeFileName)
/*Desc: This function calls all readInput() and readTime() and uses strncpy() 
and strcat() to put together full file name */
/*input: firstName, lastName, parsedID, fileName, strTime as char array 
and lateflag as bool */
//output: encodeFileName as char array
//return: None
void encode(char encodeFileName[]) {
    char firstName[21], lastName[21], parsedID[5], fileName[21], strTime[MAXTIME];
    bool lateFlag;

    //call functions
    // read student's name and lateFlag
    readInput(firstName, lastName, lateFlag);
    // read student ID and filename
    readInput(parsedID, fileName);
    // read submitted time
    readTime(strTime);

    // fill encodeFileName
    strncpy(encodeFileName, lastName, 21);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, firstName);
    if (lateFlag) {
        strcat(encodeFileName, "_LATE_");
    }
    else {
        strcat(encodeFileName, "_");
    }
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, strTime);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
}