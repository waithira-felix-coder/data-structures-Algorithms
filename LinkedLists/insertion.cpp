#include <iostream>
#include <string>
using namespace std;
struct node {
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList(){
   struct node *p = head;
   cout << "\n[";
   
   //start from the beginning
   while(p != NULL) {
      cout << " " << p->data << " ";
      p = p->next;
   }
   cout << "]";
}

//insertion at the beginning
void insertatbegin(int data){

   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data = data;

   // point it to old first node
   lk->next = head;

   //point first to new first node
   head = lk;
}
void insertatend(int data){
   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data = data;
   lk->next = NULL;            // new node is last, so next is null
   
   // if list is empty, new node becomes head
   if (head == NULL) {
       head = lk;
       return;
   }

   struct node *linkedlist = head;
   // traverse to last node
   while(linkedlist->next != NULL)
      linkedlist = linkedlist->next;

   // append new node
   linkedlist->next = lk;
}
int main(){
   insertatbegin(12);
   insertatend(22);
   insertatend(30);
   insertatend(44);
   insertatend(50);
   cout << "Linked List: ";

   // print list
   printList();
   return 0;  // indicate success
}