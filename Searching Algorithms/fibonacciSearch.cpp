/*
 Fibonacci Search Implementation in C++
  In this program, we will implement the fibonacci search algorithm in C++. The fibonacci search algorithm is an improved version of binary search that works on sorted arrays. It uses fibonacci numbers to divide the array into segments, reducing the number of comparisons needed. We will define a function called fibonacci_search that takes an array, its size, and the key to be searched as parameters. The function will return the position of the key if found, or indicate that the key is not present in the array.
  1. Generate fibonacci numbers until we find a number greater than or equal to the array size.
  2. Start from the largest fibonacci number and work backwards.
  3. Compare the element at the current position with the key.
  4. If a match is found, return the position of the element.
  5. If the key is less than the element at the current position, move to the left segment.
  6. If the key is greater than the element at the current position, move to the right segment.
  7. Repeat steps 3-6 until the key is found or all segments are exhausted.

  The time complexity of fibonacci search is O(log n), which is better than linear search but worse than binary search.
 */
#include <iostream>
using namespace std;
int min(int, int);
int fibonacci_search(int[], int, int);
int min(int a, int b){
   return (a > b) ? b : a;
}
int fibonacci_search(int arr[], int n, int key){
   int offset = -1;
   int Fm2 = 0;
   int Fm1 = 1;
   int Fm = Fm2 + Fm1;
   while (Fm < n) {
      Fm2 = Fm1;
      Fm1 = Fm;
      Fm = Fm2 + Fm1;
   }
   while (Fm > 1) {
      int i = min(offset + Fm2, n - 1);
      if (arr[i] < key) {
         Fm = Fm1;
         Fm1 = Fm2;
         Fm2 = Fm - Fm1;
         offset = i;
      } else if (arr[i] > key) {
         Fm = Fm2;
         Fm1 = Fm1 - Fm2;
         Fm2 = Fm - Fm1;
      } else
         return i;
   }
   if (Fm1 && arr[offset + 1] == key)
      return offset + 1;
   return -1;
}
int main(){
   int i, n, key, pos;
   int arr[10] = {6, 11, 19, 24, 33, 54, 67, 81, 94, 99};
   cout<<"Array elements are: ";
   for(auto j : arr){
      cout<<j<<" ";
   }
   n = 10;
   key = 67;
   cout<<"\nThe element to be searched: "<<key;
   pos = fibonacci_search(arr, n, key);
   if(pos >= 0)
      cout << "\nThe element is found at index " << pos;
   else
      cout << "\nUnsuccessful Search";
}