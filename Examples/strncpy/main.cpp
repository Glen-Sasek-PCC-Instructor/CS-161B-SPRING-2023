//*****************************************************************************
// Author: GD Iyer
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources: https://replit.com/@GDIyer/strncpy-sample#main.cpp
//*****************************************************************************

//An example program to demonstrate strncpy
//and strcat to append a new string  at the end.
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char str1[51] = "G1234-5587";
  char str2[51];
  char str3[51];
  //copies from position 6 inclusive, 5 characters to include the null character at the end
  strncpy(str2, str1 + 6, 5);
  cout << "Enter a third string: ";
  cin.getline(str3, 51);
  cout << str2 << endl;
  cout << "Now with another string concatenated to it!" <<endl;
  strcat(str2, "_");
  strcat(str2, str3);
  cout << str2 << endl;

  return 0;
}