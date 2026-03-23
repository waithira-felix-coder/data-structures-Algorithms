/*
 Exponential Search Implementation in C++
  In this program, we will implement the exponential search algorithm in C++. The exponential search algorithm is an improved version of binary search that works on sorted arrays. It starts by checking the first element and then exponentially increases the index to find the element, reducing the number of comparisons needed. We will define a function called exponential_search that takes an array, its size, and the key to be searched as parameters. The function will return the position of the key if found, or indicate that the key is not present in the array.
  1. Check if the key is present at the first position.
  2. Find the range where the key might be present by exponentially increasing the index.
  3. Perform a binary search within the identified range.
  4. If the key is found, return its position; otherwise, indicate that the key is not present in the array.

  The time complexity of exponential search is O(log n), which is better than linear search but worse than binary search.
 */
#include <iostream>
#include <cmath>
using namespace std;
int exponential_search(int[], int, int);
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
   pos = exponential_search(arr, n, key);
   if(pos >= 0)
      cout << "\nThe element is found at " << pos;
   else
      cout << "\nUnsuccessful Search";
}
int exponential_search(int a[], int n, int key){
   int i, m, low = 0, high = n - 1, mid;
   i = 1;
   m = pow(2,i);
   if(a[0] == key)
      return 0;
   while(a[m] <= key && m < n) {
      i++;
      m = pow(2,i);
      while (low <= high) {
         mid = (low + high) / 2;
         if(a[mid] == key)
            return mid;
         else if(a[mid] < key)
            low = mid + 1;
         else
            high = mid - 1;
      }
   }
   return -1;
}