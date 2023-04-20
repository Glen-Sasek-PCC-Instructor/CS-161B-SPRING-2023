//*****************************************************************************
// Author: Mac 
// Assignment: 2
// Date: 4/15/2023
// Description: a program that encodes a file based on first name, last name, if it is late or not, student ID number, time of submission, and file name. These are all separated by underscores.
// Input: Char menuOption, fName, lName, lateOption, stdID, colon, Int hour, minute
// Output: I was confused abou this part. I'll look in the feedback to see what i should do.
// Sources: zybooks, codebeuty.com kind of helps with orgaanizing the file, making it look nicer, and letting me know if I am missing a curly brace or if i have too many. 
//*****************************************************************************


#include <iostream>
#include <cstring>

using namespace std;

void welcome();
char displayMenu();
void readInput(char fName[], char lName[], bool& lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);
void encode(char encodeFileName[]);

int main() {
    char menuOption;
    char encodeFileName[100];

    welcome();

    do {
        menuOption = displayMenu();

        switch (menuOption) {
            case 'e':
                encode(encodeFileName);
                cout << "Encoded file name: " << encodeFileName << endl;
                break;
            case 'q':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
   }
    } while (menuOption != 'q');

    return 0;
}

void welcome() {
    cout << "Welcome to my fileName encoding program!!" << endl << endl;
}

char displayMenu() {
    char menuOption;
    cout << "Please pick an option below: " << endl;
    cout << "(e) Encode a file name" << endl;
    cout << "(q) Quit" << endl;
    cout << ">> ";
    cin >> menuOption;
    cout << endl;

    while (menuOption != 'e' && menuOption != 'q') {
        cout << "Invalid input. Please try again." << endl;
        cout << ">> ";
        cin >> menuOption;
        cout << endl;
 }

    return menuOption;
}

void readInput(char fName[], char lName[], bool& lateFlag) {
    cout <<"This program will ask you a few questions and generate an encoded fileName based on your answers.\n\n";
    cout << "Enter your last name: ";
    cin >> lName;
    cout << "\nEnter your first name: ";
    cin >> fName;


    for (int i = 0; fName[i] != '\0'; i++) {
        fName[i] = tolower(fName[i]);
    }
    for (int i = 0; lName[i] != '\0'; i++) {
        lName[i] = tolower(lName[i]);
    }

    char lateOption;
    cout << "\nWas your assignment Late (y/n)? ";
    cin >> lateOption;
    while (lateOption != 'y' && lateOption != 'n') {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        cout << ">> ";
        cin >> lateOption;
    }
    lateFlag = (lateOption == 'y');
}

void readInput(char ID[], char fileName[]) {
    cout << "\nEnter your Student-ID (format: 222-22-2222): ";
    char stdID[100];
    cin >> stdID;
    strncpy(ID, stdID + 7, 4);

    cout << "\nEnter the name of the file: ";
    cin >> fileName;
}

void readTime(char strTime[]) {
    int hour, minute;
    char colon;
    cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hour >> colon >> minute;

    while (hour < 0 || hour > 23 || minute < 0 || minute > 59 || colon != ':') {
        cout << "Invalid input. Please enter a valid time in military format." << endl;
        cout << ">> ";
        cin >> hour >> colon >> minute;
    }
//probably not the way I am supposed to do it but this is how I was able to convert the integers to chars
  //this also allows me to have a 0 if the user types in something like 1:1
  strTime[0] = (hour / 10) + '0';
    strTime[1] = (hour % 10) + '0';
    strTime[2] = (minute / 10) + '0';
    strTime[3] = (minute % 10) + '0';
    strTime[4] = '\0';
}

void encode(char encodeFileName[]) {
    char lName[50], fName[50], parsedID[50], fileName[50], strTime[50];
    bool lateFlag; 
    readInput(fName, lName, lateFlag);
    readInput(parsedID, fileName);
    readTime(strTime);

    
    int index = 0;
    for (int i = 0; lName[i] != '\0'; i++) {
        encodeFileName[index] = tolower(lName[i]);
        index++;
    }
    encodeFileName[index] = '_';
    index++;

    for (int i = 0; fName[i] != '\0'; i++) {
        encodeFileName[index] = tolower(fName[i]);
        index++;
    }
    encodeFileName[index] = '_';
    index++;

    if (lateFlag) {
        encodeFileName[index] = 'L';
        index++;
        encodeFileName[index] = 'A';
        index++;
        encodeFileName[index] = 'T';
        index++;
        encodeFileName[index] = 'E';
        index++;
        encodeFileName[index] = '_';
        index++;
    }

    for (int i = 0; parsedID[i] != '\0'; i++) {
        encodeFileName[index] = parsedID[i];
        index++;
    }
    encodeFileName[index] = '_';
    index++;

    for (int i = 0; strTime[i] != '\0'; i++) {
        encodeFileName[index] = strTime[i];
        index++;
    }
    encodeFileName[index] = '_';
    index++;

    for (int i = 0; fileName[i] != '\0'; i++) {
        encodeFileName[index] = tolower(fileName[i]);
        index++;
    }
    encodeFileName[index] = '\0';
}