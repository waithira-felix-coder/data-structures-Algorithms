//C++ Program
/*
 Circular Deque Implementation in C++
  In this program, we will implement a circular deque (double-ended queue) using an array. We will define the structure of the deque and implement basic operations such as push_front, push_back, pop_front, pop_back, and display. The circular deque allows us to efficiently utilize the space by connecting the rear of the deque back to the front when it reaches the end.
  1. Check if the deque is full. If it is full, return an error message.
 2. Remove the element from the front or back of the deque.
3. Increment or decrement the front or rear pointer.
4. Decrement the size of the deque.

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
// Remove element from the front
void pop_front() {
   if (isEmpty()) cout << "Deque is empty" << endl;
   else {
      cout << "Deleted from front -> " << deque[front] << endl;
      if (front == rear) front = rear = -1;
      else front = (front + 1) % SIZE;
   }
}
// Remove element from the back
void pop_back() {
   if (isEmpty()) cout << "Deque is empty" << endl;
   else {
      cout << "Deleted from back -> " << deque[rear] << endl;
      if (front == rear) front = rear = -1;
      else if (rear == 0) rear = SIZE - 1;
      else rear = rear - 1;
   }
}
// Display the deque
void display() {
   int i = front;
   if (isEmpty()) cout << "Empty Deque" << endl;
   else {
      cout << "Elements -> ";
      for (int i = front; i != rear; i = (i + 1) % SIZE) {
         cout << deque[i] << " ";
      }
      cout << deque[i];
   }
}
int main() {
   push_back(1);
   push_back(2);
   push_back(3);
   push_back(4);
   push_back(5);
   pop_front();
   pop_back();
   display();
   return 0;
}