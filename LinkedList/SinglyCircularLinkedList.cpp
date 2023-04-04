#include <iostream>
using namespace std;
class Node
{
public:
 int val;
 Node *next;
 Node(int val)
 {
  this->val = val;
  next = NULL;
 }
};
class circularList
{

 Node *head;
 Node *tail;
 int size;

public:
 circularList()
 {
  head = tail = NULL;
  size = 0;
 }

 void addAtLast(int val)
 {
  Node *t = new Node(val);

  if (head == NULL)
  {
   head = tail = t;
   head->next = head;
  }
  else
  {
   tail->next = t;
   t->next = head;
   tail = t;
  }
  size++;
 }
 void removeByIndex(int index)
 {
  if (index >= size)
  {
   cout << " Not Posiible to delete" << endl;
   return ;
  }
  if( index == 0)
  {

   tail->next = head->next;
   head = head->next;
   size --; 
   return ;
  }
  
  Node *t = NULL;
  Node *n = head;
  int i = 0;

  while (i < index)
  {
   t = n;
   n = n->next;
   i++;
  }
  t->next = n->next;
  size--;
 }
 void Display()
 {
  if (head == NULL)
   return;

  Node *t = head;
  do
  {
   cout << t->val << " -> ";
   t = t->next;
  } while (t->next != head);
  cout << t->val << endl;
 }
};
int main()
{

 circularList l;
 l.addAtLast(1);
 l.addAtLast(2);
 l.addAtLast(3);
 l.addAtLast(4);
 l.Display();
 l.removeByIndex(0); 
 l.Display();
 return 0;
}