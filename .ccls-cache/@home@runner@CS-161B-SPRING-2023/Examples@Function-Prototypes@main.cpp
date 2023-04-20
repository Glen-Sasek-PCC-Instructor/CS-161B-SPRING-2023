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

using namespace std;

// Prototypes
void hello();
void goodbye();


int main(){
  // Call
  goodbye();
}

// Implementations
void goodbye() {
  // Call 
  hello();
  cout << "Goodbye!\n";
}

void hello(){
  cout << "Hello!\n";
}