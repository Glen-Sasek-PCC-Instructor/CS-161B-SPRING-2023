//*****************************************************************************
// Author: EXAMPLE
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources:
//*****************************************************************************


#include <iostream>

using namespace std;


// PROTOTYPES

/*
Reads a list of positive integers from the user. 
A negative integer indicates the end of the input and is not stored in the array. 
*/
void readInput(int list[], int &count); 

/*
Use a loop to process each array element and return the minimum and maximum values to main by reference. These values should be printed in main().
*/
void maxmin(int list[], int count, int &max, int &min); 

/*
Return the mean to main() and in main() print the average with one decimal place using cout << fixed << setprecision(1);.
Use a loop to sum all the array elements and calculate the mean (or average). 
*/
double avgArray(int list[], int count); 

/*
Use a loop to determine if the array is a palindrome, meaning values are the same from front to back and back to front. Output "true" or "false".
*/
bool isPalindrome(int list[], int count);

/*
sort the array using the given sorting algorithm. This is called Selection Sort. Use only this algorithm to sort your list. To see how the Selection Card Sort Algorithm works, watch this video from Virginia Tech.

procedure selection sort
   list  : array of items
   count : size of list
   for i = 0 to count - 1
   // set current element as minimum 
  	min = i    
  	// go through the list and find the smallest element
  	for j = i+1 to count
     		if list[j] < list[min] then
        		min = j;
     		end if
  	end for
  	// swap the minimum element with the current element If they are not the same element
  	if indexMin != i  then
     		swap list[min] and list[i]
  	end if
   end for
end procedure

*/
void sort (int list[], int count); 

/*
After sorting, write this function to identify the median. The median is located in the middle of the array if the array’s size is odd. Otherwise, the median is the average of the middle two values. Return the median to main() and output in main() with one decimal place.
*/
double median(int list[], int count); 

int main() {
  int count = 0;
  int numbers[20];
  readInput(numbers, count);

  for(int i=0; i < count; i++) {
    cout << numbers[i] << endl;
  }
  return 0;
}

// IMPLEMENTATIONS

void readInput(int list[], int &count){
//  cerr << "TODO: void readInput(int list[], int &count)" << endl;
    bool next = true;
    do {
        int n = 0;
        cin >> n;
        if(cin) {
            if(n >= 0) {
                list[count++] = n;
            } else {
                next = false;
            }
        } else {
            cin.clear();
            cin.get();
            next = !cin.eof();          
       }
   } while(next);
}

void maxmin(int list[], int count, int &max, int &min){
  cerr << "TODO: maxmin(int list[], int count, int &max, int &min)" << endl;
}

double avgArray(int list[], int count){
  double average = 0.0;
  cerr << "TODO: double avgArray(int list[], int count)" << endl;
  return average;
}

bool isPalindrome(int list[], int count){
  bool palindrome = false;
  cerr << "TODO: bool isPalindrome(int list[], int count)" << endl;
  return palindrome;
}

void sort (int list[], int count){
  cerr << "TODO: sort (int list[], int count)" << endl;
}

double median(int list[], int count){
  double median = 0.0;
  cerr << "TODO: median(int list[], int count)" << endl;
  return median;
}
