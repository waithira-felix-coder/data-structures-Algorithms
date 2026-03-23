/*
 Jump Search Implementation in C++
  In this program, we will implement the jump search algorithm in C++. The jump search algorithm is an improved version of linear search that works on sorted arrays. It jumps ahead by a fixed number of steps to find the element, reducing the number of comparisons needed. We will define a function called jump_search that takes an array, its size, and the key to be searched as parameters. The function will return the position of the key if found, or indicate that the key is not present in the array.
  1. Calculate the optimal jump size (square root of the array size).
  2. Start from the first element and jump by the calculated size until an element greater than or equal to the key is found.
  3. Perform a linear search within the identified block.
  4. If the key is found, return its position; otherwise, indicate that the key is not present in the array.
  
  The time complexity of jump search is O(√n), which is better than linear search but worse than binary search.
 */
#include<stdio.h>
#include<math.h>
int jump_search(int[], int, int);
int main(){
   int i, n, key, index;
   int arr[12] = {0, 6, 12, 14, 19, 22, 48, 66, 79, 88, 104, 126};
   int len = sizeof(arr)/sizeof(arr[0]);
   printf("Array elements are:");
   for(int j = 0; j<len; j++){
      printf(" %d", arr[j]);
   }
   n = 12;
   key = 66;
   printf("\nThe element to be searched: %d\n", key);
   index = jump_search(arr, n, key);
   if(index >= 0)
      printf("The element is found at position %d", index+1);
   else
      printf("Unsuccessful Search");
   return 0;
}
int jump_search(int arr[], int n, int key){
   int i, j, m, k;
   i = 0;
   m = sqrt(n);
   k = m;
   while(arr[m] <= key && m < n) {
      i = m;
      m += k;
      if(m > n - 1)
         return -1;
   }

   // linear search on the block
   for(j = i; j<m; j++) {
      if(arr[j] == key)
         return j;
   }
   return -1;
}