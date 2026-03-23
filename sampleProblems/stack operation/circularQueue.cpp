/*
 Circular Queue Implementation in C++
  In this program, we will implement a circular queue using a linked list. We will define the structure of the node and implement basic operations such as enqueue, dequeue, and display. The circular queue allows us to efficiently utilize the space by connecting the rear of the queue back to the front when it reaches the end.
*/
#include <iostream>
using namespace std;

struct Node {
   int data;
   struct Node* link;
};

struct Node* front = NULL;

struct Node* rear = NULL;

// Check if the queue is empty
int isEmpty() {
   return front == NULL;
}

// Adding an element
void enQueue(int value) {
   struct Node* newNode = new Node();
   newNode->data = value;
   newNode->link = NULL;
   if(isEmpty()) {
      front = newNode;
   } else {
      rear->link = newNode;
   }
   rear = newNode;
   rear->link = front;
   cout << "\n Inserted " << value;
}

// Deleting an element
int deQueue() {
   int value;
   if(isEmpty()) {
      cout << "\n Queue is Empty";
      return -1;
   } else {
      struct Node* temp = front;
      value = temp->data;
      if(front == rear) {
         front = rear = NULL;
      } else {
         front = front->link;
         rear->link= front;
      }
      free(temp);
      return value;
   }
}

// Display the queue
void display() {
   struct Node* temp = front;
   if(isEmpty()) {
      cout << "\n Queue is Empty\n";
   } else {
      cout << "\n Front -> ";
      do {
         cout << temp->data << " ";
         temp = temp->link;
      } while(temp != front);
      cout << endl;
   }
}

int main() {
   //Inserting elements to queue
   enQueue(14);
   enQueue(22);
   enQueue(6);
   // Display elements present in the queue
   cout <<"Initial Queue ";
   display();
   // Deleting elements from queue
   cout << "Element Removed"<<deQueue() << endl;
   // Display elements present in the queue
   cout <<"Queue after deletion an element: "<< endl; 
   display();
   // Inserting elements to queue
   enQueue(9);
   //Showing the rear of the queue
   cout <<"Rear Element"<< rear->data<< endl;
   enQueue(20);
   //Showing the front of the queue
   cout <<"Front Element"<< front->data<< endl;
   cout <<"Final Queue "<< endl;
   display();
   return 0;
}