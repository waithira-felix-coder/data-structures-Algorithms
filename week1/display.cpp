//displays the contents of the array

#include <iostream>

using namespace std;

int main(){
  int LA[]= {1,3,5,7,8};
  int n=5, i;
  //int i;
  cout<<"The original array elements are: ";

  for(i=0; i<n; i++)
  cout<<"LA["<< i <<"] ="<<LA[i]<< endl;
   
  return 0;
}