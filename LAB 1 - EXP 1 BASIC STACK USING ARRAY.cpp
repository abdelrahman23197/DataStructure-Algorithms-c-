#include <iostream>
#define Stack_Size 50
using namespace std;
class STACK{
private :
    int top;     //POINTER to current value
    int stack_array[Stack_Size]; //array to store values
public:
    //functions defination
     STACK();            //constructor
    int top_V();         //returns value at top
    bool isEmpty();      //returns true if top=-1
    bool isFull();       //return true if top=size-1
    void Show();         //show contents of stack
    void push(int v);    //push value to stack ,increment the pointer
    int pop();           //return the value,decrement the pointer
};

STACK::STACK(){
top=-1;
}
int STACK::top_V(){
return stack_array[top];
}
bool STACK::isEmpty(){
if(top==-1)
    return true;
else
    return false;
}
bool STACK::isFull(){
if(top== Stack_Size-1)
    return true;
else
    return false;
}
void STACK::Show(){
    if(top == -1)
    {
        cout<<"Stack is Empty"<<endl;
    }
    else {
        for(int i=top;i>=0;--i)
            {
                cout<<stack_array[i]<<endl;}
    }
}
void STACK::push(int v){
    if(!isFull()){
top++;
stack_array[top]=v;
    }
    else {
        cout<<"Stack is OverFlow";
    }
}

int STACK::pop(){
if(isEmpty())
{
    cout<<"stack is Underflow";
}
else {
    int topvalue;
    topvalue=stack_array[top];
    top--;
    return topvalue;

}
}

int main()
{   STACK s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.Show();
    s.pop();
    s.Show();
    s.push(2);
    s.Show();


    return 0;
}
