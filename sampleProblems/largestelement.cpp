//Find the largest element in ana array

#include<iostream>
using namespace std;

int main(){
  int arr[5] ={1,3,5,7,9};
  int max = arr[0]; //starts with the first element

  //Compares with the next element( if larger --update max, then repeats)

  for(int i= 1; i<5; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  cout<<"Largest element: "<< max <<endl;
}