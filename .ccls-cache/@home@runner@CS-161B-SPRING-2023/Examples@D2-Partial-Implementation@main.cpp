/******************************************************************************
# Author:           Darth Vadar and Luke Sykwalker
# Lab:              Discussion #1
# Date:             April 20, 2021
# Description:      This progam prompts for an age and calculates birth year
# Input:            string name, integer age
# Output:           integer birth year
# Sources:          None
#******************************************************************************/


/*
With your programming partner, write a program that creates a password for a user, given the following information:

Ask the user for a word they remember. 
Longer words are best, and phrases are even better. 

The word may be a dog or cat you had years ago, or even a street you lived on. 

For this example I will use a street I lived on: Mower Street. 

Take the first word of the phrase and ignore the rest. So, just Mower in this case.

Pick a number you can remember, such as the year you graduated high school. 

For this example, I will use the year I graduated from college: 1980. 

Limit this to a 4 digit number. 
Use a char array, and make sure every character of the char array is a number.

Pick a symbol you will remember. 
  Make sure it is readily available on your keyboard so you don't have to hunt for it. 
  For this example I will use ^.
Assume all char arrays have 20 characters.

Hint: 
  Make a new string, 
  copy the first word to the new string. 
  Then concatenate the 4 digit number. 
  And then finally concatenate the character.  
  
Use C-string library functions whenever you can to manipulate the strings. 

Don't forget to add a null character at the end of the new string after you have finished copying the characters.

You must use only char arrays for this course - no String class.

Ex: If the input is:

Mower Street
1991 
$
the output is:

Your strong password is: Mower1991$
Ex: If the input is:

Gayathri Iyer 
2024
& 
the output is:

Your strong password is: Gayathri2024&
Task:

Start with the end - design what the user will see when they run your program.
Design first, then write your C++ program.

Must be able to read c-string with spaces.
Make sure data validation is done appropriately for the 4 digit number!

You must have at least 2 other functions other than main. 

Functions must have parameters.

*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

const int PHRASE_MAX_CHARS = 20;
const int YEAR_CHARS = 4;
const int PASSWORD_MAX_CHARS = PHRASE_MAX_CHARS + YEAR_CHARS + 1;// 1 for symbol

const char PASSWORD_LABEL[] = "Your strong password is: ";

// Read a character repeat until in range.
char getCharacterInRange(char low, char high);


void generatePassword(char phrase[], char year[], char symbol, char password[]);


int main() {
  char phrase[PHRASE_MAX_CHARS + 1]; // Plus 1 for null terminator.
  char year[YEAR_CHARS + 1];
  char symbol;
  char password[PASSWORD_MAX_CHARS + 1];

  cin.getline(phrase, PHRASE_MAX_CHARS);

  for(int i = 0; i < YEAR_CHARS; i++) {
    year[i] = getCharacterInRange('0', '9');
  }
  year[YEAR_CHARS] = '\0';

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  symbol = cin.get();

  generatePassword(phrase, year, symbol, password);
  
  cout << PASSWORD_LABEL << password;
  
  return 0;
}

void generatePassword(char phrase[], char year[], char symbol, char password[]){
  int i = -1;
  do {
    i++;
    password[i] = phrase[i]; 
  } while (i < strlen(phrase) && !isspace(phrase[i]));

  password[i] = '\0';
  
  strcat(password, year);

  i = strlen(password);
  
  password[i] = symbol;
  password[i+1] = '\0';
}

char getCharacterInRange(char low, char high){
  char c = '\0';
  do {
    c = cin.get();
  } while (c < low || c > high);
  return c;
}



