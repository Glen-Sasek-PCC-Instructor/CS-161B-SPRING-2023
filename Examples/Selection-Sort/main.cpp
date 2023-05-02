//*****************************************************************************
// Author:
// Assignment:
// Date:
// Description:
// Input:
// Output:
// Sources: Assignment 3
//*****************************************************************************

#include <iostream>

using namespace std;

/*
procedure selection sort
list : array of items
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
//swap the minimum element with the current element If they are not the same element
if indexMin != i then
swap list[min] and list[i]
end if
end for
end procedure
*/

void selection_sort(int list[], int count);

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

  selection_sort(list, count);

  for(int i = 0; i < count; i++) {
    cout << list[i] << endl;
  }  
  return 0;
}

void selection_sort(int list[], int count) {
  int min = 0;
  for(int i = 0; i <= count - 1; i++){
    min=i;
    for(int j = i + 1; j <= count -1; j++){
      if(list[j] < list[min]){
        min=j;
      }
    }
    if(min != i) {
      int n = list[min];
      list[min] = list[i];
      list[i] = n;
    }
  }
}