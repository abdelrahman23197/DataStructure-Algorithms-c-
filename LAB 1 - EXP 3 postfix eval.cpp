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
    float top_V();         //returns value at top
    bool isEmpty();      //returns true if top=-1
    bool isFull();       //return true if top=size-1
    void Show();         //show contents of stack
    void push(float v);    //push value to stack ,increment the pointer
    float pop();           //return the value,decrement the pointer
};

STACK::STACK(){
top=-1;
}
float STACK::top_V(){
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
void STACK::push(float v){
    if(!isFull()){
top++;
stack_array[top]=v;
    }
    else {
        cout<<"Stack is OverFlow";
    }
}

float STACK::pop(){
if(isEmpty())
{
    cout<<"stack is Underflow";
}
else {
    float topvalue;
    topvalue=stack_array[top];
    top--;
    return topvalue;

}
}
float math_operation(float op1,float op2,char operat)
{
    switch(operat){
    case '+': return op2+op1;
    break;
    case '-': return op2-op1;
    break;
    case '*': return op2*op1;
    break;
    case '/': return op2/op1;
    break;
    default : return 0;
    }
}
float postfix_eval(string exp)
{
    float result=0;
 STACK s;
 for(int i=0;i<exp.length();i++)
 {
   if(isdigit(exp[i]))
   {
     //if it is number push it into the stack
     s.push(exp[i]-'0');
   }
   else if(exp[i] == '+' || exp[i] == '-' ||exp[i] == '/' ||exp[i] == '*'){
    //if it is operand pop 2 of  operands of stack
    //evaluate result and push it into stack
    float op1=s.pop();
    float op2=s.pop();
    result=math_operation(op1,op2,exp[i]);
    s.push(result);
   }
 }
return s.top_V();
}
int main()
{
string postfix_exp="382/+5-";
cout<<postfix_eval(postfix_exp);

    return 0;
}
