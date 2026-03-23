/*
 Binary Search Implementation in C++
  In this program, we will implement the binary search algorithm in C++. The binary search algorithm is a more efficient searching technique that works on sorted arrays. It repeatedly divides the search interval in half until the target element is found or the interval becomes empty. We will define a function called binary_search that takes a sorted array, its bounds, and the key to be searched as parameters. The function will return the position of the key if found, or indicate that the key is not present in the array.
  1. Initialize the lower and upper bounds of the search interval.
  2. Calculate the middle index of the current search interval.
  3. Compare the middle element with the key.
  4. If a match is found, return the position of the element.
  5. If the key is less than the middle element, search in the left half.
  6. If the key is greater than the middle element, search in the right half.
  7. Repeat steps 2-6 until the key is found or the search interval becomes empty.
  
  The best case time complexity of binary search is O(1) when the key is found at the middle position, and the worst case time complexity is O(log n) when the key is not present in the array or found at one of the ends.
  */
#include <iostream>
using namespace std;
void binary_search(int a[], int low, int high, int key){
   int mid;
   mid = (low + high) / 2;
   if (low <= high) {
      if (a[mid] == key)
         cout << "Element found at index: " << mid << endl;
      else if(key < a[mid])
         binary_search(a, low, mid-1, key);
      else if (a[mid] < key)
         binary_search(a, mid+1, high, key);
   } else if (low > high)
      cout << "Unsuccessful Search" <<endl;
}
int main(){
   int i, n, low, high, key;
   n = 5;
   low = 0;
   high = n-1;
   int a[10] = {12, 14, 18, 22, 39};
   key = 22;
   binary_search(a, low, high, key);
   key = 23;
   binary_search(a, low, high, key);
   return 0;
}