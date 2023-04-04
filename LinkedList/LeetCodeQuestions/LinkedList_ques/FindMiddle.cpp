#include <iostream>
#include<unordered_map>
using namespace std;
// creating  a class named as Node

class Node
{
public:
 int val;
 Node *next;
 Node()
 {
  val = 0;
  next = NULL;
 }
 Node(int val)
 {
  next = NULL;
  this->val = val;
 }
};
class LinkedList
{
 Node *head;
 Node *tail;
 int size ; 

public:
 LinkedList()
 {
  head = NULL;
  tail = NULL;
  size =0; 
 }

 int getSize()
 {
  return size;
 }
 void addLast(int val)
 {
  Node *t = new Node(val);
  if (head == NULL)
  {
   head = tail = t;
  }
  else
  {
   tail->next = t;
   tail = t;
  }
  size++;
 }


 void display()
 {
  if (head == NULL)
   return;

  Node *t = head;
  while (t->next != NULL)
  {
   cout << t->val << " -> ";
   t = t->next;
  }
  cout << t->val << endl;
 }
 // adding cycle after a pariculr indez 

  int getMid()
  {
    if(head == NULL ) return -1 ; 
    if(head->next == NULL)
       return head->val; 

     Node * fast = head; 
     Node * slow = head ;

     while(fast)
     {
      fast = fast->next ; 
      if(fast)
      {
      fast = fast->next;
      slow = slow->next ; 
      }
     } 
     return slow->val ;
  }
};
int main()
{
 LinkedList list ; 
 list.addLast(5); 
 list.addLast(3); 
 list.addLast(2); 
 list.addLast(1); 
 list.addLast(0); 
  list.addLast(6); 
 list.addLast(7); 
 list.addLast(8); 
 list.addLast(10); 
 list.display();
 int mid = list.getMid();
 cout<<mid<<endl; 
  return 0 ; 
}
