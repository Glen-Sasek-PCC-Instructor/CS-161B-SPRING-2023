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
#include <limits>

using namespace std;
const int ZIP_CHARS = 5;
const int MAX_NAME_CHARS = 50;

int main() {
	char zip_code[ZIP_CHARS+1];
  char full_name[MAX_NAME_CHARS+1];
  
  cout << "Zip code: ";
  cin >> zip_code;

  // Use ignore to remove the remaining line and endline character.
  // Always ignore if you need to remove '\n' between cin and get or getline.

  // UNCOMMENT NEXT LINE TO FIX ERROR
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Full name: ";
  cin.getline(full_name, MAX_NAME_CHARS);
  // It will appear getline is not working but it is reading the '\n' left 
  // on the input stream and interpreting it correctly as the end of the line
  // resulting in full_name being empty.

  cout << endl << endl;
  cout << "Zip code: " << zip_code << endl;

  // Without ignore full_name will be empty.
  cout << "Full name: " << full_name << endl;

  
	return 0;
}