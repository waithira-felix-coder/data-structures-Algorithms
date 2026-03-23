/* Circular Queue Implementation in C++ 
Dequeue operation
1.Check if the circular queue is empty.
2.If the queue is not empty, store the element at the front index.
3.If the front and rear are equal, set the front and rear to -1.
4.Else, increase the front index by 1 using the formula front = (front + 1) % SIZE.
5.At last print the deleted element.
*/
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
// Deleting an element
int deQueue() {
   int element;
   if(isEmpty()) {
      cout << "Queue is empty" << endl;
      return(-1);
   } else {
      element = items[front];
      if (front == rear) {
         front = -1;
         rear = -1;
      } else {
         front = (front + 1) % SIZE;
      }
      cout << endl << "Deleted element " << element << endl;
      return(element);
   }
}
// Display the queue
void display() {
   int i;
   if(isEmpty()) cout << endl << "Empty Queue" << endl;
   else {
      cout << "Items " << endl;
      for(i = front; i!=rear; i=(i+1)%SIZE) {
         cout << items[i] << " ";
      }
      cout << items[i] << endl;
   }
}
int main() {
   enQueue(1);
   enQueue(2);
   enQueue(3);
   display();
   deQueue();
   display();
   return 0;
}