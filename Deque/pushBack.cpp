/*
 Circular Deque Implementation in C++
  In this program, we will implement a circular deque (double-ended queue) using an array. We will define the structure of the deque and implement basic operations such as push_front, push_back, pop_front, pop_back, and display. The circular deque allows us to efficiently utilize the space by connecting the rear of the deque back to the front when it reaches the end.
  1. Check if the deque is full. If it is full, return an error message.
2. Increment/ the front pointer by one.
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

// Insert element at the back
void push_back(int element) {
   if (isFull()) {
      cout << "Deque is full" << endl;
   } else {
      if (front == -1) { // First insertion
         front = 0;
         rear = 0;
      } else if (rear == SIZE - 1 && front != 0) { // Wrap around
         rear = 0;
      } else { // Normal case
         rear++;
      }
      deque[rear] = element;
      cout << "Inserted -> " << element << endl;
   }
}

// Display the deque
void display() {
   if (isEmpty()) {
      cout << "Empty Deque" << endl;
   } else {
      cout << "Elements -> ";
      int i = front;
      while (true) {
         cout << deque[i] << " ";
         if (i == rear) break; // Stop when the last element is printed
         i = (i + 1) % SIZE; // Move circularly
      }
      cout << endl;
   }
}

int main() {
   push_back(1);
   push_back(2);
   push_back(3);
   push_back(4);
   push_back(5);
   display();
   return 0;
}