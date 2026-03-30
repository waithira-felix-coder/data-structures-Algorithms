/*
Remove from front
increment front

*/


#include<iostream>
using namespace std;

#define SIZE 5
int queue[SIZE] ={10,20,30};
int front =0, rear =2;

void dequeue(){
  if(front == -1 || front > rear){
    cout<<"Queue Underflow\n";
    return;
  }

  cout<<"Dequeued: "<<queue[front]<<endl;
  front++;
}

int main(){
  dequeue();
  dequeue();
}