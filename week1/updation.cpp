//updates an element at a  given index. 

#include <iostream>

using namespace std;
int main(){
  int LA[] = {1,3,5,7,8};
  int item = 10, n=5, i=0;
  //int i = 0, j = n;
  cout<<"the original array elements are:\n    "  <<endl;

   for(i=0; i<n; i++)
   //cout<<"LA["<<i<<"]= "<<LA[i]<<endl;
   cout<< LA[1] <<endl;
   LA[2] = item;
    cout<<"The array after updation  are :\n";
    

   for(i=0; i< n; i++){
    cout<<"LA["<<i<<"] = "<<LA[i] <<endl;
   }
   
return 0;

}