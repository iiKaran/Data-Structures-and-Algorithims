#include <iostream>
using namespace std;
class queue
{
 int front, rear, size, maxSize;
 int *arr;

public:
 queue(int maxSize)
 {
  this->maxSize = maxSize;
  front = rear = -1;
  size = 0;
  arr = new int[maxSize];
 }
 bool isFull()
 {
  if (size >= maxSize)
   return 1;
  else
  {
   return 0;
  }
 }
 bool isEmpty()
 {
  return front == -1;
 }

 void push(int val)
 {
  rear++;
  if (!isFull())
  {
   arr[rear] = val;
   size++;
   if (front == -1)
   {
    front = 0;
   }
   else
   {
    cout << "Queue is full" << endl;
   }
  }
  else
  {
   rear--;
  }
 }
 int pop()
 {
  if (isEmpty())
  {
   cout << "queue is empty" << endl;
   return -1;
  }
  int a = arr[front];
  front++;
  if (front > rear)
   front = -1;

  size--;
  return a;
 }
 void display()
 {
  if (isEmpty())
  {
   cout << "Queue is empty" << endl;
   return;
  }
  for (int i = front; i <= rear; i++)
  {
   cout << arr[i] << ",";
  }
  cout << endl;
 }
};
int main()
{
 queue q(1);
 q.push(1);

 q.display();
 cout << endl
      << "Popped Value " << q.pop() << endl;
 q.pop();
 return 0;
}