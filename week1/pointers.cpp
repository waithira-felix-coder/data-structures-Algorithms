#include<iostream>

using namespace std;
int main(){
    int a = 10;
    int *ptr = &a; // pointer to an integer variable

    cout << "Value of a: " << a << endl; // Output: 10
    cout << "Address of a: " << &a << endl; // Output: address of a
    cout << "Value of ptr: " << ptr << endl; // Output: address of a
    cout << "Value pointed to by ptr: " << *ptr << endl; // Output: 10

    return 0;
}