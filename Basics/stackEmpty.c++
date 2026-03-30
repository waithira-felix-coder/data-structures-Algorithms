//Stack is empty when: top = -1

#include <iostream>
using namespace std;

int top= -1;

bool isEmpty() {
  return (top == -1);
}

int main() {
  if (isEmpty())   
  cout<<"Stack is Empty";
  else
  cout<<"Stack is Not Empty";
} 