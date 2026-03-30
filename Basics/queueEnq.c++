/*First element: front =0,  always insert at rear.

enqueue(10): front=0, rear=0
enqueue(20): rear=1
enqueue(30): rear=2

Queue:[10,20,30]
*/
#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
  if (rear == SIZE - 1){
    cout <<"Queue Overflow\n";
    return;
  }

  if(front == -1)
  front = 0;

  rear++;
  queue[rear] = value;

  cout<<value <<"Enqueued\n";
}

int main(){
  enqueue(10);
  enqueue(20);
  enqueue(30);
}