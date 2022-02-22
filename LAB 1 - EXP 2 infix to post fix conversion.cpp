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
int priority(char c){
//difference between operators
//if it is operator stack is popped higher priority operators
//operators is pushed into top of stack based on priority or there is open bracket

if(c=='-' || c=='+')
    return 1;
else if(c=='*' || c=='/')
    return 2;
else if(c=='^')
    return 3;
else
    return 0;

}

string infix_to_postfix(string exp){
//create empty stack of charachters
STACK s;
//create Empty String for Output
string output="";

for(int i=0;i<exp.length();i++)
{
//loop over input expression
if(exp[i]==' ')
continue; //if it is space skip this step of loop
else if(isdigit(exp[i]) || isalpha(exp[i]))
//if it is alphabetical or number ,it is added to output
output+=exp[i];
else if(exp[i]=='(')
//if it is open bracket it is pushed into stack
s.push(exp[i]);
else if(exp[i]==')')
{
//pop all data untill find open bracket,addit to expression
while(s.top_V() != '(')
{
 output+=s.top_V();
 s.pop();
}
//still top value at (
s.pop(); //remove (
}
else {
//if it is operation
//only pushed into stack if priority bigger than top value of stack
//if it is lower priority all operands poped and added to output untill it is lower than current operator
while( priority(exp[i]) <= priority(s.top_V())  && !s.isEmpty()  ){
//if priority of operator of string < at top ,pop all untill char of priority > current operand
// don't pop if empty
output+=s.top_V();
s.pop();
}
// push operand if it is higher priority
s.push(exp[i]);


}



}
//after finIsh check all stack should be empty
while(!s.isEmpty()){
output+=s.top_V();
s.pop();
}
return output;
}
int main()
{
    string infixexpression="(3+2)+7/2*((7+3)*2)";
    cout<<infix_to_postfix(infixexpression)<<endl;

    return 0;
}
