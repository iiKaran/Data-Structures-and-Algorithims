#include<bits/stdc++.h>
using namespace std ;
class ListNode{
  public : 
  int val ; 
  ListNode * next ; 
  ListNode()
  {
   val=0; 
   next = nullptr; 
  }
  ListNode(int val)
  {
   this->next = nullptr; 
   this->val = val ; 
  }
  // method of stack 

};
class Stack{
    ListNode * head ;
    int size ; 
    public: 
    Stack()
    {
     head = nullptr ; 
    }
    bool isEmpty()
    {
      return head== nullptr;
    }
    void push( int val)
    {
     ListNode * t = new ListNode(val); 
     if( head ==nullptr)
     head = t ; 
     else {
         t->next = head ; 
         head = t ; 
     }
    }

    int pop(){
     if(isEmpty())
     {
      cout<<"The Stack Is Empty : "<<endl; 
      return -1 ; 
     }
     else 
     {
      int d = head->val ; 
      head = head->next ;
      return d ; 
     }
      
    }
    void display()
    {
      if(isEmpty()){
       cout<<"Stack is empty "<<endl; 

      }
      else {
       ListNode * temp = head ; 
       while(temp->next != NULL)
       {
        cout<<temp->val<<"->";
        temp = temp->next ;  
       }
       cout<<temp->val<<endl; 
      }
    }
};
int main()
{
    
    Stack stk ; 
    stk.push(1); 
    stk.push(2);
    stk.push(3); 
    stk.display(); 
    stk.pop(); 
    stk.pop(); 
    stk.pop(); 
    cout<<endl<<"After popiing "<<endl; 
    stk.display(); 
    return 0 ; 

}