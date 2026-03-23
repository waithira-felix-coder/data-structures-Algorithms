/*
 Circular Deque Implementation in C++
  In this program, we will implement a circular deque (double-ended queue) using an array. We will define the structure of the deque and implement basic operations such as push_front, push_back, pop_front, pop_back, and display. The circular deque allows us to efficiently utilize the space by connecting the rear of the deque back to the front when it reaches the end.
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
   return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Check if the deque is empty
bool isEmpty() {
   return front == -1;
}

// Insert element at the front
void push_front(int element) {
   if (isFull()) {
      cout << "Deque is full" << endl;
      return;
   }
   
   if (isEmpty()) { // First element being inserted
      front = rear = 0;
   } 
   else if (front == 0) { // Wrap around
      front = SIZE - 1;
   } 
   else {
      front--;
   }

   deque[front] = element;
   cout << "Inserted -> " << element << endl;
}

// Display the deque
void display() {
   if (isEmpty()) {
      cout << "Empty Deque" << endl;
      return;
   }

   cout << "Elements -> ";
   int i = front;
   while (true) {
      cout << deque[i] << " ";
      if (i == rear) break;  // Stop at last element
      i = (i + 1) % SIZE;    // Circular increment
   }
   cout << endl;
}

int main() {
   push_front(1);
   push_front(2);
   push_front(3);
   push_front(4);
   push_front(5);
   display();
   return 0;
}