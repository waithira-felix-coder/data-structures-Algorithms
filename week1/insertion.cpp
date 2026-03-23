//Adds an element ata the given index. 
#include <iostream>

using namespace std;
int main(){
  int LA[3] = {}, i;
  cout<<"Array Before Insertion: "<<endl;
   for(i=0; i<3; i++)
   cout<<"LA["<<i<<"]= "<<LA[i]<<endl;

   //Prints garbage values
   cout<< "Inserting elements.."<<endl;
   cout<<"Array After Insertion: "<<endl;

   //Points Array values
   
   for(i=0; i<3; i++){
    LA[i]= i+2;
    cout<<"LA["<<i<<"]="<<LA[i] <<endl;

   }
   return 0;
}