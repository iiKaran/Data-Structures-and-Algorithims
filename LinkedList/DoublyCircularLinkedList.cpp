#include <iostream>
using namespace std;
class Node
{
public:
 int val;
 Node *next;
 Node *prev;
 Node()
 {
  val = 0;
  next = NULL;
  prev = NULL;
 }
 Node(int val)
 {
  next = NULL;
  prev = NULL;
  this->val = val;
 }
};

class DoublyCircularLinkedList
{
 Node *head;
 Node *tail;
 int size;

public:
DoublyCircularLinkedList()
 {
  size = 0;
  head = tail = NULL;
 }

 void insertAtLast(int value)
 {
  Node *t = new Node(value);

  if (head == NULL)
  {
   head = tail = t;
   t->next = head ; 
   head->prev = head ;
   size++;
   return;
  }
  else
  {
   t->next = head ; 
   head->prev = t;
   t->prev = tail;
   tail->next = t;
   tail = t;

   size++;
  }
 }
 void display()
 {
  if (head == NULL)
   return;

  Node *t = head;
 do
  {
   cout << t->val << " <-> ";
   t = t->next;
  } while (t->next != head);
  cout << t->val << endl;
 }

 void removeByIndex(int index)
 {
  if (index >= size)
  {
   cout << "Value at the passed index doesnot exist " << endl;
   return;
  }

  if (index == 0)
  {
   head = head->next;
   tail->next = head ;

   if (head)
   {
    head->prev = tail;
   }
  }
  else
  {
   Node *t = head;

   int i = 1;
   while (i <= index)
   {
    i++;
    t = t->next;
   }
   t->prev->next = t->next;
   if (t->next)
    t->next->prev = t->prev;
   size--;
  }
 }
};

int main()
{
 DoublyCircularLinkedList dl;
 dl.insertAtLast(1);
 dl.insertAtLast(2);
 dl.insertAtLast(3);
 dl.insertAtLast(4);
 dl.insertAtLast(5);

 dl.display();
 dl.removeByIndex(2);
 dl.display();
 return 0;
}