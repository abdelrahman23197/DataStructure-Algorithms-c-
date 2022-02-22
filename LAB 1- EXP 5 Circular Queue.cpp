#include <iostream>
#define Queue_Size 5
using namespace std;
class Queue{
private :
    int Queue_Data[Queue_Size];
    int Front;
    int Rear;

public:
    Queue(); //constructor to the queue
    bool isFull();
    bool isEmpty();
    void enqueue(int v);
    int dequeue();
    void Show();
    void Front_Rear();
};

Queue::Queue(){
Front=-1;
Rear=-1;
}
bool Queue::isFull(){
if ((Front == 0 && Rear==Queue_Size - 1) || Front==Rear+1)
    //if front at first element and Rear at last ,or rear get before front
    return true;
else
    return false;
}
bool Queue::isEmpty(){
if (Front == -1)
    return true;
else
    return false;
}
void Queue::enqueue(int v){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
        //if queue is full can't add element
    }
    else {
       if(Front==-1){
    //queue is first intialized
    //increase front to be 0
    Front=0; }
    Rear = (Rear+1) % Queue_Size ;
    Queue_Data[Rear]=v; //add value to the rear
    }
}
int Queue::dequeue(){
if(isEmpty()){
    cout<<"Queue is Empty"<<endl;
}
else {
    int data_dequeued=Queue_Data[Front];
    if(Front == Rear){
        //after series of enqueue and dequeue back to be empty again
    Front=-1;
    Rear=-1;
    }
    else {
        Front = (Front +1) % Queue_Size;
    }
    return data_dequeued;
}
}
void Queue::Show(){
if(isEmpty()){
    cout<<"Empty    Queue"<<endl;
}
else{
        int j;
        if(Front<Rear || (Front == 0 && Rear == 0)){
            for(int i=Front;i<=Rear;i++)
                cout<<Queue_Data[i]<<"\t";
        }
        else if(Front>Rear) {
    for( j= Front;j!=Rear;j = (j+1)% Queue_Size)
cout<<Queue_Data[j]<<"\t";
cout<<Queue_Data[j];
        }

}
cout<<endl;
}
void Queue::Front_Rear(){
cout<<"Front ="<<Front<<endl;
cout<<"Rear = "<<Rear<<endl;
}
int main()
{
Queue q;
q.Show();
cout<<"****************"<<endl;
q.enqueue(1);
q.Show();
cout<<"****************"<<endl;
q.enqueue(2);
q.Show();
cout<<"****************"<<endl;
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
q.Show();
cout<<"****************"<<endl;
q.enqueue(6);
q.Show();
cout<<"****************"<<endl;
q.Front_Rear();
cout<<"****************"<<endl;
q.dequeue();
q.Front_Rear();
q.Show();
cout<<"****************"<<endl;
q.enqueue(10);
q.Show();
cout<<"****************"<<endl;
q.dequeue();
q.dequeue();
q.Show();
cout<<"****************"<<endl;
q.dequeue();
q.dequeue();
q.dequeue();
q.Show();
q.dequeue();
cout<<"****************"<<endl;
q.enqueue(4);
q.Show();
cout<<"****************"<<endl;
q.enqueue(5);
q.Show();

}
