#include<iostream>
using namespace std;
int main(){

  int arr[] = {3,5,7,9,1};
  int i=0;
  int pos =30;
//Traverse (access all elements in the array)
  for(i=0; i<4; i++)
    cout<< "arr["<< i<<"]= " << arr[i] <<endl;

    arr[2] = pos; //updates the value of index 2

    cout<<"Updated arrays are: "<<endl;

  for(i=0; i<4; i++){
    
    cout<< "arr["<<i<<"]= " << arr[i] <<endl; //prints the updated array values
  }
  


}