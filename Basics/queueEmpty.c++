/*Queue is empty when:
  front==-1 OR front>rear
*/

#include <iostream>
using namespace std;

int front =-1, rear=-1;

bool isEmpty(){
  return (front ==-1 || front >rear);
}

int main(){
  if(isEmpty())
  cout<<"Queue is Empty";
  else
  cout<<"Queue is Not Empty";
}