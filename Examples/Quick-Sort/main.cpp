//*****************************************************************************
// Author:
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources: https://en.wikipedia.org/wiki/Quicksort
//*****************************************************************************

#include <iostream>

using namespace std;

/*
// Sorts a (portion of an) array, divides it into partitions, then sorts those
algorithm quicksort(A, lo, hi) is 
  // Ensure indices are in correct order
  if lo >= hi || lo < 0 then 
    return
    
  // Partition array and get the pivot index
  p := partition(A, lo, hi) 
      
  // Sort the two partitions
  quicksort(A, lo, p - 1) // Left side of pivot
  quicksort(A, p + 1, hi) // Right side of pivot

// Divides array into two partitions
algorithm partition(A, lo, hi) is 
  pivot := A[hi] // Choose the last element as the pivot

  // Temporary pivot index
  i := lo - 1

  for j := lo to hi - 1 do 
    // If the current element is less than or equal to the pivot
    if A[j] <= pivot then 
      // Move the temporary pivot index forward
      i := i + 1
      // Swap the current element with the element at the temporary pivot index
      swap A[i] with A[j]

  // Move the pivot element to the correct pivot position (between the smaller and larger elements)
  i := i + 1
  swap A[i] with A[hi]
  return i // the pivot index
Sorting the entire array is accomplished by quicksort(A, 0, length(A) - 1).
*/

void quick_sort(int list[], int low, int high);

int partition(int list[], int low, int high);

int main() {
  const int MAX_SIZE = 100000;
  int list[MAX_SIZE];
  int count = 0;
	do{
    cin >> list[count];
    if(cin) {
      count++;
    }
  } while (cin && !cin.eof());

  quick_sort(list, 0, count -1);

  for(int i = 0; i < count; i++) {
    cout << list[i] << endl;
  }  
  return 0;
}

void quick_sort(int list[], int low, int high){
  if(low >= high || low < 0){
    return;
  }
    
  // Partition array and get the pivot index
  int p = partition(list, low, high);
      
  // Sort the two partitions
  quick_sort(list, low, p - 1); // Left side of pivot
  quick_sort(list, p + 1, high); // Right side of pivot
}

int partition(int list[], int low, int high){
  int pivot = list[high]; // Choose the last element as the pivot

  // Temporary pivot index
  int i = low - 1;

  for (int j = low; j <= high - 1; j++){
    // If the current element is less than or equal to the pivot
    if (list[j] <= pivot) { 
      // Move the temporary pivot index forward
      i = i + 1;
      // Swap the current element with the element at the temporary pivot index
      int n = list[i];
      list[i] = list[j];
      list[j] = n;
    }
  }
  // Move the pivot element to the correct pivot position (between the smaller and larger elements)
  i = i + 1;
  // swap A[i] with A[hi]
  int n = list[i];
  list[i] = list[high];
  list[high] = n;  
  return i; // the pivot index  
}