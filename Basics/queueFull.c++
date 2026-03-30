//rear ==SIZE-1

#include <iostream>
using namespace std;

#define SIZE 3
int rear =2;

bool isFull(){
  return(rear ==SIZE -1);
}

int main(){
  if(isFull())
  cout<<"Queue is Full";
  else
  cout<<"Queue is Not Full";
}