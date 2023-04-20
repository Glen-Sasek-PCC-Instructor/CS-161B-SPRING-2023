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
// Only #include libraries being used.
// Do not #include <bits/stdc++>

using namespace std;

// Prototype
void SwapValues(int &userVal1, int &userVal2);

int main() {
  int n1 = 0;
  int n2 = 0;
  cin >> n1 >> n2;
  SwapValues(n1, n2);
  cout << n1 << " " << n2 << endl;
	return 0;
}

// Iplementation
void SwapValues(int &userVal1, int &userVal2){
  int n = 0;
  n = userVal1;        
  userVal1 = userVal2;
  userVal2 = n;
}