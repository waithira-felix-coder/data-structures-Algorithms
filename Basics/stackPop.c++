/*
Remove element at top
Decrement top

Initial: [10,20,30], top =2
pop(): removes 30 , top =1
pop(): removes 20, top =0
*/


#include <iostream>
using namespace std;

#define SIZE 5
int stack[SIZE] ={10,20,30};
int top = 2;

void pop() {
  if (top == -1) {
    cout <<"Stack Underflow\n";
    return;
  }
  cout<<"popped: " <<stack[top]<<endl;
  top--;

}

int main(){
  pop();
  pop();
}