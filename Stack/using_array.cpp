#include <iostream>
#define maxsize 100
using namespace std; 
class stack{
 private:
     int top ; 
     int arr[maxsize];
     int size;
 public: 
    stack()
    {
     top = -1 ; 
     size =0; 
    } 
    bool isEmpty()
    {
        return (top == -1) ; 

    }
    bool isFull()
    { 
         return (top == maxsize -1) ; 
    }
    bool push( int element)
    {
        top++; 
        if(isFull()){
            cout<<"Element cant be inserted Array Full \n"; 
            return false ; 
        }
        
        arr[top] = element ; 
        return true ;
    }
    int pop()
    {
          if(isEmpty())
          {
            cout<<"No element presented"<<endl; 
            return -1 ; 
          }
          else{
            return arr[top--];
          }
    }
    bool Top()
    {
        if(isEmpty())
        {
            cout<<"No Element Present ="<<endl ; 
            return false; 
        }
        else{
            cout<<"Element "<<arr[top]<<"Is at Top"<<endl; 
            return true ;
        }
        return true  ; 
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty "<<endl ;
            return ; 
        }
        else{
            for(int i = top; i>=0;i--)
            {

                cout<<arr[i]<<" , ";
            }
        }
    }


};
int main()
{
    stack stk; 
    stk.push(1); 
    stk.push(2);
    stk.push(3);
    // stack follows last in first out so the last entry is 3 which gets popped first
    // time complexity - o(1)
    stk.display();
    stk.pop(); 
    cout<<endl; 
    stk.display();
 
 return 0;
}