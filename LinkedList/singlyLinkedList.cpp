#include <iostream>
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
void removeByIndex( int index)
{
    if( index >= size)
    {
     cout<<"Not Possible"<<endl ; 
     return ; 
    }
    if(index == 0)
    {
     head = head->next;
     size--;
     return  ;
    }
    Node * t = NULL ; 
    Node * n = head ; 
    int i =0 ; 
    while(i < index )
    {
          t = n ; 
          n= n->next ; 
          i++;
    }
    t->next= n->next ; 
    size--; 

}
void removeFirstOccurence( int value){
  
  Node * t = head;
  int i =0; 
  while(t!= NULL)
  {
   if(t->val== value){
    removeByIndex(i); 
    break ;
   }
   i++; 
   t= t->next ; 
   
  }
}
 
Node * reverse()
{
 Node * prev= NULL; 
 Node * curr=head; 
 Node * next= NULL ; 
 while(curr)
 {
  next = curr->next; 
  curr->next = prev ; 
  prev = curr ; 
  curr= next ; 
 }
 return prev ;
}
 void display(Node * given)
 {
  if (given == NULL)
   return;

  Node *t = given;
  while (t->next != NULL)
  {
   cout << t->val << " -> ";
   t = t->next;
  }
  cout << t->val<< endl;
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
};

int main()
{
 LinkedList l;
 l.addLast(1);
 l.addLast(3);
 l.addLast(3);
 l.addLast(5);
 l.display(); 
Node * rev = l.reverse(); 
// getting the reverse 
l.display(rev);
// calling the display function that is overloaded 

 return 0;
}