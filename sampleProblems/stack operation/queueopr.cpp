/* C++ program to implement queue operations 
operations such as insert, remove, peek, isEmpty, isFull and size using an array. Also checks if the queue is empty or full before performing these operations.
*/
#include <iostream>
using namespace std;
#include <string>
#define MAX 6
int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int peek(){
   return intArray[front];
}
bool isEmpty(){
   return itemCount == 0;
}
bool isFull(){
   return itemCount == MAX;
}
int size(){
   return itemCount;
}
void insert(int data){
   if(!isFull()) {
      if(rear == MAX-1) {
         rear = -1;
      }
      intArray[++rear] = data;
      itemCount++;
   }
}
int removeData(){
   int data = intArray[front++];
   if(front == MAX) {
      front = 0;
   }
   itemCount--;
   return data;
}
int main(){
   
   /* insert 5 items */
   insert(3);
   insert(5);
   insert(9);
   insert(1);
   insert(12);
   insert(15);
   cout<<"Queue size: "<<size();
   cout<<"\nQueue: ";
   for(int i = 0; i < MAX; i++){
       cout<<intArray[i]<<" ";
   }
   if(isFull()) {
      cout<<"\nQueue is full!";
   }

   // remove one item
   int num = removeData();
   cout<<"\nElement removed: "<<num;
   cout<<"\nQueue size after deletion: "<<size();
   cout<<"\nElement at front: " <<peek();
}