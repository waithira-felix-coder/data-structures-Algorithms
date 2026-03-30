/*Stack is full when: 
         top == SIZE -1
*/


#include <iostream>
using namespace std;

#define SIZE 3
int stack[SIZE] ={10,20,30};
int top =2;

bool isFull(){
  return (top == SIZE -1);
}

int main(){
  if (isFull())
  cout<<"Stack is Full";
  else
  cout<<"Stack is Not Full";
}