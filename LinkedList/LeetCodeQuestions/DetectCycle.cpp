#include <iostream>
#include <unordered_map>
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
 int size;

public:
 LinkedList()
 {
  head = NULL;
  tail = NULL;
  size = 0;
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

 void createcycle(int index)
 {
  if (index >= size)
   return;

  int i = 0;
  Node *t = head;

  while (i < index)
  {
   i++;
   t = t->next;
  }
  t->next = head->next;
 }
 bool detectCycle()
 {
  unordered_map<Node *, bool> mp;
  Node *t = head;
  while (t != NULL)
  {

   if (mp[t] == 1)
    return true;
   mp[t] = 1;
   t = t->next;
  }
  return false;
 }
};

int main()
{
 LinkedList list;
 list.addLast(1);
 list.addLast(2);
 list.addLast(3);
 // list.addlast(4);
 // list.createcycle(2);
 cout << "There is a cycle " << list.detectCycle();
 // list.display();

 return 0;
}
// optimized approch : 
// use the fast and the slow pointer to find the cycle