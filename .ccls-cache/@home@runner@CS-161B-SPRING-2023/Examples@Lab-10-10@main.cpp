//*****************************************************************************
// Author:
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources:
//*****************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CHARS = 51;// support 50 characters plus the null character end sentinel.

// Return true if array contains string
bool array_contains_string(char arr[][MAX_CHARS], int array_size, char str[]);

// Print to ostream in reverse
// ostream parameter is to support output to file or console
// Does not append new line or pad output
void print_reverse(ostream &sout, char* str, int size);

int main() {
  
   /* Type your code here. */
  
  const int QUIT_SENTINEL_COUNT = 3;
  char QUIT_SENTINELS[QUIT_SENTINEL_COUNT][MAX_CHARS] = {"Quit", "quit", "q"};

  char str[MAX_CHARS];
  bool repeat = true;
  do {
    cin.getline(str, MAX_CHARS);
    repeat = !array_contains_string(QUIT_SENTINELS, QUIT_SENTINEL_COUNT, str);
    if(repeat) { // Only display if input was not quit sentinel
      print_reverse(cout, str, strlen(str));
      cout << endl;
    }
  } while(repeat);

   return 0;
}

bool array_contains_string(char arr[][MAX_CHARS], int array_size, char str[]){
  bool found = false;
  for(int i = 0; !found && i < array_size; i++){
    found = strcmp(arr[i], str) == 0;
  }
  return found;
}

void print_reverse(ostream &sout, char* str, int size){
  for(int i = size-1; i >=0; i--){
    sout << str[i];
  }
}