/*
 Sublist Search Implementation in C++
  In this program, we will implement the sublist search algorithm in C++. The sublist search algorithm is used to check if a linked list is a sublist of another linked list. We will define a function called sublist_search that takes two linked lists as parameters. The function will return true if the second list is a sublist of the first list, otherwise it will return false.
 */
#include <iostream>
using namespace std;
struct Node {
   int data;
   Node* next;
};
Node *newNode(int key){
   Node *val = new Node;
   val-> data= key;
   val->next = NULL;
   return val;
}
bool sublist_search(Node* list_ptr, Node* sub_ptr){
   Node* ptr1 = list_ptr, *ptr2 = sub_ptr;
   if (list_ptr == NULL && sub_ptr == NULL)
      return true;
   if ( sub_ptr == NULL || (sub_ptr != NULL && list_ptr == NULL))
      return false;
   while (list_ptr != NULL) {
      ptr1 = list_ptr;
      while (ptr2 != NULL) {
         if (ptr1 == NULL)
            return false;
         else if (ptr2->data == ptr1->data) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
         } else
            break;
      }
      if (ptr2 == NULL)
         return true;
      ptr2 = sub_ptr;
      list_ptr = list_ptr->next;
   }
   return false;
}
int main(){
   Node *list = newNode(2);
   list->next = newNode(5);
   list->next->next = newNode(3);
   list->next->next->next = newNode(3);
   list->next->next->next->next = newNode(6);
   list->next->next->next->next->next = newNode(7);
   list->next->next->next->next->next->next = newNode(0);
   Node *sub_list = newNode(3);
   sub_list->next = newNode(6);
   sub_list->next->next = newNode(7);
   bool res = sublist_search(list, sub_list);
   if (res)
      cout << "Is the sublist present in the list? "<<res;
}