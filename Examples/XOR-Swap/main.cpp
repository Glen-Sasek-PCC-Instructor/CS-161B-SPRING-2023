//*****************************************************************************
// Author:
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources: https://en.wikipedia.org/wiki/XOR_swap_algorithm
//          https://en.cppreference.com/w/cpp/language/operator_arithmetic
//*****************************************************************************

#include <iostream>
// Only #include libraries being used.
// Do not #include <bits/stdc++>

using namespace std;

// Prototype
void SwapValues(int&, int&);

int main() {
  int n1 = 0;
  int n2 = 0;
  cin >> n1 >> n2;
  SwapValues(n1, n2);
  cout << n1 << " " << n2 << endl;
	return 0;
}

// Iplementation
/*
X := X XOR Y; // XOR the values and store the result in X
Y := Y XOR X; // XOR the values and store the result in Y
X := X XOR Y; // XOR the values and store the result in X
*/
void SwapValues(int &x, int &y){
  x = x ^ y;
  //y = y ^ x;
  x = x ^ y;
}