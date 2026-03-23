//C++ Program
#include <iostream>
using namespace std;
#define SIZE 5
int items[SIZE];
int front = -1, rear =-1;
// Check if the queue is full
int isFull() {
   if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
   return 0;
}
// Check if the queue is empty
int isEmpty() {
   if(front == -1) return 1;
   return 0;
}
// Adding an element
void enQueue(int element) {
   if(isFull()) cout << "Queue is full\n";
   else {
      if(front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
      cout << endl << "Inserted " << element << endl;
   }
}
// Display the queue
void display() {
   int i;
   if(isEmpty()) cout << endl << "Empty Queue" << endl;
   else {
      cout << "Items";
      for(i = front; i!=rear; i=(i+1)%SIZE) {
         cout << items[i] << " ";
      }
      cout << items[i];
   }
}
int main() {
   enQueue(1);
   enQueue(2);
   enQueue(3);
   enQueue(4);
   enQueue(5);
   display();
   return 0;
}