#include<iostream>
using namespace std;
int main(){
  int num =20;
  int *ptr = &num;

  *ptr =50;

  cout<<"Updated value: "<<num;

}