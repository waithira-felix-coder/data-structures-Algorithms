/*
 Interpolation Search Implementation in C++
  In this program, we will implement the interpolation search algorithm in C++. The interpolation search algorithm is an improved version of binary search that works on uniformly distributed sorted arrays. It estimates the position of the target element based on the values at the boundaries of the search interval. We will define a function called interpolation_search that takes an array, its size, and the key to be searched as parameters. The function will return the position of the key if found, or indicate that the key is not present in the array.
  1. Initialize the lower and upper bounds of the search interval.
  2. Calculate the estimated position of the target element.
  3. Compare the element at the estimated position with the key.
  4. If a match is found, return the position of the element.
  5. If the key is less than the element at the estimated position, search in the left half.
  6. If the key is greater than the element at the estimated position, search in the right half.
  7. Repeat steps 2-6 until the key is found or the search interval becomes empty.

  The best case time complexity of interpolation search is O(1) when the key is found at the estimated position, and the worst case time complexity is O(n) when the array is not uniformly distributed.
 */
#include<iostream>
using namespace std;
#define MAX 10

// array of items on which linear search will be conducted.
int list[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int interpolation_search(int data){
   int lo = 0;
   int hi = MAX - 1;
   int mid = -1;
   int comparisons = 1;
   int index = -1;
   while(lo <= hi) {
      cout << "Comparison " << comparisons << endl;
      cout << "lo : " << lo << " list[" << lo << "] = " << list[lo] << endl;
      cout << "hi : " << hi << " list[" << hi << "] = " << list[hi] << endl;
      comparisons++;
      
      // probe the mid point
      mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
      cout << "mid = " << mid;
      
      // data found
      if(list[mid] == data) {
         index = mid;
         break;
      } else {
         if(list[mid] < data) {
            
            // if data is larger, data is in upper half
            lo = mid + 1;
         } else {
            
            // if data is smaller, data is in lower half
            hi = mid - 1;
         }
      }
   }
   cout << "\nTotal comparisons made: " << (--comparisons);
   return index;
}
int main(){
   
   //find location of 33
   int location = interpolation_search(33);
   
   // if element was found
   if(location != -1)
      cout << "\nElement found at location: " << (location+1);
   else
      cout << "Element not found.";
   return 0;
}