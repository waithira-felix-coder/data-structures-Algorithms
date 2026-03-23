#include<iostream>
using namespace std;


 //node structure
struct Node{
  int data;
  Node* next;

};

//function to reverse linked list
void reverseList(Node** head){
  Node* prev =NULL;
  Node* current =*head;
  while(current != NULL){
    Node* next = current ->next;
    current ->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

//function to print linkedList
void printList(Node* head){
  while (head != NULL){
    cout<< head ->data <<" ";
    head;
  }
}
