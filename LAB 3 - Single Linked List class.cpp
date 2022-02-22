#include <iostream>

using namespace std;
struct node {
int data;
node *next;
};
class Linked_List {
private :
    node *head;
public :
    Linked_List(); //create new empty List with a value
    void show();   //traverse through linked list & show data
    void insert_newnode(int value); //insert node at end
    void insert_nodefirst(int value);//insert node at first
    int number_of_elements();        //return number of elements of list
    void insert_atposition(int pos,int value); //insert as specific position of list
    node* Search_by_value(int value); //returns address of node has specific value,first match
    void delete_first(); //delete first node
    void delete_last();   //delete second node
    void delete_pos(int pos); //delete node at specific position
    void reverse_list();
};
Linked_List::Linked_List(){
    //constructor head pointer pointed to null when declared
head=NULL;
}
void Linked_List::insert_newnode(int value){
        node* new_node = new node; //create new node
        new_node->data=value;  //ASSIGN Value
        new_node->next=NULL;   //make it point to null as it is last
if(head==NULL)
{
    //STILL NO LIST CREATED
    //make head point to new node
    head=new_node;
    return;
}
else {
        //make last node in old list point to new node
    node *current=head; //create new pointer to traverse whole linked list to add the new node at last
    while(current->next != NULL)
    {
        current=current->next;
    }
    //now temp point to last node
    current->next=new_node;

}
}
void Linked_List::show(){
node* current=head; //new pointer to traverse through list
if(head==NULL){
    cout<<"List is Empty"<<endl;
}
else{
 while(current != NULL)
{
    //current pointer loop when its value be null indicar=tes end of list
  cout<<current->data<<"\t";
  current=current->next;
}
cout<<endl;
}

}
void Linked_List::insert_nodefirst(int value){
node* newnode=new node;
newnode->data=value;
if(head==NULL)
{
    //STILL NO LIST CREATED
    //make head point to new node
    head=newnode;
    head->next=NULL; //only one node
    return;
}
else {
    newnode->next=head; //make new node point to the same as head
    head=newnode;  //make head point to new node
}
}
int Linked_List::number_of_elements(){
node* temp=head;
int counter =0;
while(temp!=NULL){
 counter+=1;       //loops over list to return number of elements untill pointer has null
 temp=temp->next;
}
return counter;
}
void Linked_List::insert_atposition(int pos,int value){

int num=number_of_elements();
if(pos==0){
    //if user required to put it at first
    insert_nodefirst(value);
}
else if(pos == num-1){
    //if user put it at last
    insert_newnode(value);
}
else if(pos <= num) {
    //at middle
 node* new_node=new node; //create new node to store the value
 new_node->data=value; //store value to new node
 int counting=0;   //store value at which we want to add the new node
 node* next_node=head; //two pointers to traverse one ahead of another
 node* perv_node=head;
 while(next_node != NULL && counting!=pos){
   counting+=1;
   perv_node=next_node;
   next_node=next_node->next;
 }
//at end of loop perv_node has address of pervious
//next_node has address of next node
 perv_node->next=new_node; //make perv point to new node
 new_node->next=next_node;  //make new node point to net node
}
else {
    cout<<"this position is out of linked list"<<endl;
}
}
node* Linked_List::Search_by_value(int value){
node* current=head;
while(current!=NULL)
{while(current->data != value ){
    current=current->next;
}
return current;
}
}
void Linked_List::delete_first(){
    node* copy_head=head;
    if(number_of_elements()==1)
    {
       head=NULL;
       delete copy_head;
    }
else if(number_of_elements()>1){
  head=head->next;
copy_head->next=NULL;
delete copy_head;
}
else {
    cout<<"List is Empty"<<endl;
}
}
void Linked_List::delete_last(){
    node* current=head;
    node* perv=head;
    if(number_of_elements()==1)
    {
        head=NULL;
        delete current;
    }
    else if(number_of_elements()>1){
       while(current->next!=NULL){
      perv=current;
      current=current->next;
    }
    perv->next=NULL;
    delete current;
    }
    }

void Linked_List::delete_pos(int pos){
int n=number_of_elements();
if(pos==0){
    delete_first();
}
else if(pos == n-1){
    delete_last();
}
else if (pos < n-1){
  int counting=0;   //store value at which we want to add the new node
 node* next_node=head; //two pointers to traverse one ahead of another
 node* perv_node=head;
 while(next_node != NULL && counting!=pos){
   counting+=1;
   perv_node=next_node;
   next_node=next_node->next;
 }
 perv_node->next=next_node->next;
 delete next_node;
}
else {
    cout<<"this position is out of list"<<endl;
}
}
void Linked_List::reverse_list(){
node* current=head;
node* perv=NULL;
node* next=NULL;
while(current!=NULL){
    //LOOP over all list
    //thees two lines to make current node point to pervious
    next=current->next; //save next node to complete traversing
    current->next=perv; //at cuurent node make it point to pervious
    //these two lines to jump to next node ,update prev and current
    perv=current;
    current=next;
}
//current point to null,perv point to last node
head=perv;

}
int main()
{
Linked_List li;
li.show();
//li.delete_pos(0);
//li.insert_atposition(0,3);
//cout<<li.number_of_elements();
//li.insert_atposition(1,5);
li.insert_newnode(1);
//li.delete_pos(0);
li.insert_newnode(2);
li.insert_newnode(3);
li.insert_newnode(4);
li.show();
li.insert_nodefirst(10);
li.insert_nodefirst(5);
li.show();
cout<<li.number_of_elements()<<endl;
li.insert_atposition(1,30);
li.show();
li.insert_atposition(4,16);
li.show();
li.insert_atposition(8,3);
li.show();
cout<<"************"<<endl;
li.delete_first();
li.show();
li.delete_last();
li.show();
li.delete_pos(4);
li.show();
li.delete_pos(0);
li.show();
li.delete_pos(5);
li.reverse_list();
li.show();

    return 0;
}
