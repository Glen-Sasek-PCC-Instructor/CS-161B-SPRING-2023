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

int main() {
	int count = 0;
  int pivot = 0;
  cin >> count;
  int list[count];
  for(int i =0; i < count; i++){
    cin >> list[i];
  }
  cin >> pivot;
  /*
  for(int i = 0; i < count; i++){
    cout << list[(i + pivot) % count] << " ";
  }
  */

  int tail = count-1;
  for(int i = tail; i >= pivot; i--) {
    int n = list[tail];
    for(int j = tail; j > 0; j--) {
      list[j] = list[j-1];
    }
    list[0] = n;
  }
  
  for(int i =0; i < count; i++){
    cout << list[i] << " ";
  }
  cout << endl;

  
	return 0;
}