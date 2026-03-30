/*
Insert element at the top
Increment top
*/

#include <iostream>
using namespace std;

#define SIZE 5
int Stack[SIZE];
int top = -1;

void push(int value){
  if (top == SIZE -1){
    cout<<"Stack Overflow\n";
    return;
  }
  top ++;
  Stack[top] = value;
  cout<<value<<"pushed into stack\n";
}

int main(){
  push(10);
  push(20);
  push(30);
}
