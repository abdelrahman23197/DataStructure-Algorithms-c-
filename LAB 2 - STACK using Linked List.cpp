#include <iostream>

using namespace std;
struct node {
int data;
node *next;
};
class STACK {
private : node* top;
public :
    STACK();
    bool isEmpty();
    void show();
    bool isFull();
    void push(int v);
    int top_v();
    int pop();

};
STACK::STACK(){
top = NULL;
}
bool STACK::isEmpty(){
if(top==NULL){
    return true;
}
else
    return false;
}
void STACK::show(){
if(isEmpty())
{
 cout<<"STACK IS EMPTY"<<endl;
}
else {
node* current=top;
while(current != NULL)
{
    //current pointer loop when its value be null indicates end of list
  cout<<current->data<<"\t";
  current=current->next;
}
cout<<endl;
}
}
bool STACK::isFull(){
node* newnode= new(nothrow) node; //nothrow makes newnode has NULL Value if stack is completed
if(!newnode){ //if !NULL= true ,allocation failed
    return true;
}
else {
    delete newnode; //delete allocated memory
    return false;   //can add new  node
}
}
void STACK::push(int v){
    if(isFull()){
        cout<<"STACK IS FULL"<<endl;
    }
    else {
node* newnode=new node;
newnode->data=v;
if(top==NULL){
        //if stack is empty
newnode->next=NULL; //make newnode point to null
top=newnode;     //make top point to newnode
}
else {
    //if stack has nodes
    newnode->next=top; //make new node point to same node as top
    top=newnode;       //make top points to same as node
}
    }
}
int STACK::top_v(){
if(top == NULL)
{
    cout<<"Stack is FULL "<<endl;
    return -99999;
}
else {
    return top->data;
}
}
int STACK::pop(){
if(isEmpty()){
cout<<"Stack is Empty "<<endl;
}
else {
node* temp =top;
int val =temp->data;
top=top->next;
delete temp;
return val;
}
}


int main()
{
STACK s;
s.pop();
cout<<s.top_v()<<endl;
s.push(1);
s.show();
s.push(2);
s.show();
s.push(3);
s.show();
s.pop();
s.show();
s.push(4);
s.show();
cout<<s.top_v();
    return 0;
}
