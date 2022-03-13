#include <iostream>

using namespace std;
struct node {
int data;
node *next;
};
class Queue {
private : node* FRONT;
          node* REAR;
public :
    Queue();
    bool isEmpty();
    void show();
    bool isFull();
    void enqueue(int v);
    int dequeue();
};
Queue::Queue(){
FRONT=NULL;
REAR=NULL;
}
bool Queue::isEmpty(){
if(FRONT==NULL && REAR==NULL){
    return true;
}
else
    return false;
}
void Queue::show(){
if(isEmpty())
{
 cout<<"Queue IS EMPTY"<<endl;
}
else {
node* current=FRONT;
while(current != NULL)
{
    //current pointer loop when its value be null indicates end of list
  cout<<current->data<<"\t";
  current=current->next;
}
cout<<endl;
}
}
bool Queue::isFull(){
node* newnode= new(nothrow) node; //nothrow makes newnode has NULL Value if stack is completed
if(!newnode){ //if !NULL= true ,allocation failed
    return true;
}
else {
    delete newnode; //delete allocated memory
    return false;   //can add new  node
}
}
void Queue::enqueue(int v){
    if(isFull()){
        cout<<"Queue IS FULL"<<endl;
    }
    else {
node* newnode=new node;
newnode->data=v;
newnode->next=NULL; //make newnode point to null as enqueue always at last
if(FRONT==NULL && REAR==NULL){
        //if stack is empty
FRONT=newnode;     //make front and rear pointers point to newnode
REAR=newnode;
}
else {
    //if stack has nodes
    REAR->next=newnode;       //make last node in list point to newnode
    REAR=newnode; //make Rear point to new node
}
    }
}
int Queue::dequeue(){
if(isEmpty()){
cout<<"Queue is Empty "<<endl;
}
else if(FRONT==REAR){
    //queue has one element
    int value=FRONT->data;
    node* temp=FRONT;
    FRONT=NULL;
    REAR=NULL;
    delete temp;
    return value;
}
else {
        //queue has more than one element
int value=FRONT->data;
node* temp=FRONT; //store address of first node
FRONT=FRONT->next; //make front point to next node
delete temp; //delete node at the front
return value;
}
}


int main()
{
Queue q;
q.dequeue();
q.enqueue(1);
q.show();
q.enqueue(2);
q.show();
q.enqueue(3);
q.show();
q.dequeue();
q.show();
q.enqueue(4);
q.show();
q.dequeue();
q.show();
q.dequeue();
q.show();
q.dequeue();
q.show();
q.enqueue(2);
q.show();
q.enqueue(3);
q.show();
    return 0;
}
