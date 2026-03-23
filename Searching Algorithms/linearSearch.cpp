/*
 Linear Search Implementation in C++
  In this program, we will implement the linear search algorithm in C++. The linear search algorithm is a simple searching technique that checks each element of the array sequentially until it finds the target element or reaches the end of the array. We will define a function called linear_search that takes an array, its size, and the key to be searched as parameters. The function will return the position of the key if found, or indicate that the key is not present in the array.
  1. Iterate through each element of the array.
  2. Compare the current element with the key.
  3. If a match is found, return the position of the element.
  4. If the end of the array is reached without finding the key, indicate that the key is not present in the array.
  
  The best case time complexity of linear search is O(1) when the key is found at the first position, and the worst case time complexity is O(n) when the key is not present in the array or found at the last position.
  */
#include <iostream>
using namespace std;
void linear_search(int a[], int n, int key){
   int i, count = 0;
   for(i = 0; i < n; i++) {
     if(a[i] == key) { // compares each element of the array
       cout << "The element is found at position " << i+1 <<endl;
       count = count + 1;
     }
   }
   if(count == 0) // for unsuccessful search
     cout << "The element is not present in the array" <<endl;
}
int main(){
   int i, n, key;
   n = 6;
   int a[10] = {12, 44, 32, 18, 4, 10};
   key = 18;
   linear_search(a, n, key);
   key = 23;
   linear_search(a, n, key);
   return 0;
}