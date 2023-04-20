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


int main() {
  const int QUIT_SENTINEL = -1;
  bool continue_flag = true;

  cout << "Enter integers to add, [" << QUIT_SENTINEL << "] to quit." << endl;

  int sum = 0;

  while(continue_flag){
    int n = 0;
    
    // Read input
    cin >> n;

    // Validate Input
    if(cin){
      // Check Sentinel value
      if(QUIT_SENTINEL == n){
        // Conditionally update continue flag
        continue_flag = false;
      } else {
        // Conditionally execute loop
        sum += n; // sum = sum + n;
      }
    } else {
      // Handle invalid input
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error :(" << endl;
    }
  }

  cout << "SUM: " << sum << endl;
}