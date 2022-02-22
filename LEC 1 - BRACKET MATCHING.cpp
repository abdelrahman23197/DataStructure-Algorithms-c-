#include <iostream>
#define Stack_Size 50
using namespace std;
class STACK{
private :
    int top;     //POINTER to current value
    char stack_array[Stack_Size]; //array to store values
public:
    //functions defination
     STACK();            //constructor
    char top_V();         //returns value at top
    bool isEmpty();      //returns true if top=-1
    bool isFull();       //return true if top=size-1
    void Show();         //show contents of stack
    void push(char v);    //push value to stack ,increment the pointer
    char pop();           //return the value,decrement the pointer
};

STACK::STACK(){
top=-1;
}
char STACK::top_V(){
if(isEmpty())
    return '\0';
else
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
void STACK::push(char v){
    if(!isFull()){
top++;
stack_array[top]=v;
    }
    else {
        cout<<"Stack is OverFlow";
    }
}

char STACK::pop(){
if(isEmpty())
{
    cout<<"stack is Underflow";
}
else {
    char topvalue;
    topvalue=stack_array[top];
    top--;
    return topvalue;

}
}
bool pairing(char open,char close){
//function to compare between opening bracket and closed bracket { }
if(open=='(' && close ==')') return true;
else if(open=='{' && close =='}') return true;
else if(open=='[' && close ==']') return true;
else return false;
}
bool balanced(string exp)
{
    //function returns true if each beacket is closed
    STACK s;
    for(int i=0;i<exp.length();i++){
            //loop for string if it is opening push it into the stack
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            s.push(exp[i]);
           }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                //if it is empty return false as no brackets
                //compare this with top of stack if it is not >not matched return falls
                //if matched bracket pop it
                    if(s.isEmpty())
                    return false;
                    else if(pairing(s.top_V(),exp[i]) == false)
                    return false;
                    else
                    s.pop();
                }

    }


    //check after looping all the string if stack is empty it is matched
    if(s.isEmpty()) return true;
    else return false;
}
int main()
{
    string expression="{{ab}c}";
    if(balanced(expression))
    {
        cout<<"matched"<<endl;
    }
    else
        cout<<"unmatched"<<endl;


    return 0;
}
