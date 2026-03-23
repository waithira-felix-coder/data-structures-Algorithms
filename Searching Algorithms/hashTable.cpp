/*
 Hash Table Implementation in C++
  In this program, we will implement a hash table in C++. A hash table is a data structure that stores key-value pairs and provides efficient insertion and retrieval operations. We will define a function called hashCode to calculate the hash value of a key, and another function called search to find an element in the hash table.
  1. Define a structure for the data item that will be stored in the hash table.
  2. Create a hash table using an unordered_map to store the key-value pairs.
  3. Implement the hashCode function to calculate the hash value of a key.
  4. Implement the search function to retrieve the value associated with a given key.

  this concept is widely used in various applications such as databases, caching, and indexing. The time complexity of search operations in a hash table is O(1) on average, making it an efficient data structure for storing and retrieving data.
 */
#include <iostream>
#include <unordered_map>
using namespace std;
#define SIZE 10 // Define the size of the hash table
struct DataItem {
   int key;
};
unordered_map<int, DataItem*> hashMap; // Define the hash table as an unordered_map

int hashCode(int key) {
   // Return a hash value based on the key
   return key % SIZE;
}

DataItem* search(int key) {
   // get the hash
   int hashIndex = hashCode(key);
   
   // move in the map until an empty slot is found or the key is found
   while (hashMap[hashIndex] != nullptr) {
      // If the key is found, return the corresponding DataItem pointer
      if (hashMap[hashIndex]->key == key)
         return hashMap[hashIndex];
      
      // go to the next cell
      ++hashIndex;
      
      // wrap around the table
      hashIndex %= SIZE;
   }
   
   // If the key is not found, return nullptr
   return nullptr;
}

int main() {
   
   // Initializing the hash table with some sample DataItems
   DataItem item2 = {25}; // Assuming the key is 25
   DataItem item3 = {64}; // Assuming the key is 64
   DataItem item4 = {22}; // Assuming the key is 22
   
   // Calculate the hash index for each item and place them in the hash table
   
   int hashIndex2 = hashCode(item2.key);
   hashMap[hashIndex2] = &item2;
   
   int hashIndex3 = hashCode(item3.key);
   hashMap[hashIndex3] = &item3;
   
   int hashIndex4 = hashCode(item4.key);
   hashMap[hashIndex4] = &item4;
   
   // Call the search function to test it
   int keyToSearch = 64; // The key to search for in the hash table
   DataItem* result = search(keyToSearch);
   cout<<"The element to be searched: "<<keyToSearch;
   if (result != nullptr) {
      cout << "\nElement found";
   } else {
      cout << "\nElement not found";
   }
   
   return 0;
}