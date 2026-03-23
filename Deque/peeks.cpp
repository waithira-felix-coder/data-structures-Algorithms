/* C++ Program to implement peek operations in a circular deque (double-ended queue) using an array. The peek operations allow us to view the front and rear elements of the deque without removing them. We will define the structure of the deque and implement the peek_front and peek_back functions to retrieve the front and rear elements, respectively. The circular deque allows us to efficiently utilize the space by connecting the rear of the deque back to the front when it reaches the end.
 1. Check if the deque is full. If it is full, return an error message.
  2. Increment/ the front pointer by one.
  3. Insert the element at the front position.
  4. Increment the size of the deque.
  
*/
#include <iostream>
using namespace std;
#define SIZE 5
int deque[SIZE];
int front = -1, rear = -1;
// Check if the deque is full
bool isFull() {
   if ((front == 0 && rear == SIZE - 1) || front == rear + 1) return true;
   return false;
}
// Check if the deque is empty
bool isEmpty() {
   if (front == -1) return true;
   return false;
}
// Insert element at the back
void push_back(int element) {
   if (isFull()) cout << "Deque is full" << endl;
   else {
      if (front == -1) front = 0;
      if (rear == SIZE - 1) rear = 0;
      else rear = rear + 1;
      deque[rear] = element;
      cout << "Inserted -> " << element << endl;
   }
}
// Get the element from the front
int peek_front() {
   if (isEmpty()) {
      cout << "Deque is empty" << endl;
      return -1;
   } else {
      return deque[front];
   }
}
// Get the element from the back
int peek_back() {
   if (isEmpty()) {
      cout << "Deque is empty" << endl;
      return -1;
   } else {
      return deque[rear];
   }
}

int main() {
   push_back(1);
   push_back(2);
   push_back(3);
   push_back(4);
   push_back(5);
   cout << "\nElement at front: " << peek_front() << endl;
   cout << "Element at back: " << peek_back() << endl;
   return 0;
}