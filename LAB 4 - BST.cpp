#include <iostream>
#include<queue>

using namespace std;
struct node {
int data;
node* right;
node* left;
};
class BST {
private :
    node* root;
    void insert_val(node* current,int value);//insert node at specific position
    void BFS_level_order(node* current); //print first order traversal
    node* SEARCH(node* current,int value); //search for a specific value in tree and return its address
    void inorder(node* current); //inorder traversal
    void preorder(node* current); //preorder traversal
    void postorder(node* current);//post order traversal
    node* findMin(node* current);//find address of min
    node* findMax(node* current);//find address of max
    node* remove_node(node* current,int value);
public :
    BST();  //constructor intialize root pointer
    void insert_val(int value){insert_val(root,value);} //pass root address to pointer that we traverse current
    void BFS_level_order(){BFS_level_order(root);}
    node* SEARCH(int value){return SEARCH(root,value);}
    void inorder(){inorder(root);cout<<endl;}
    void preorder(){preorder(root);cout<<endl;}
    void postorder(){postorder(root);cout<<endl;}
    node* findMin(){findMin(root);}
    node* findMax(){findMax(root);}
    void remove_node(int value){
        remove_node(root,value);
        }
};
BST::BST(){
root=NULL;
}
void BST::insert_val(node* current,int value){
if(current==NULL){
//if root points to NULL ,create new node & make root points to it
node* newnode=new node;
newnode->data=value;
newnode->left=NULL;
newnode->right=NULL;
root=newnode;
}
else {
//tree has elements
    if(value<current->data){
        //value is smaller than current node
        if(current->left==NULL){
            //if current node doesn't have left child
            //create node and make current left points to it
            node* newnode=new node;
            newnode->data=value;
            newnode->left=NULL;
            newnode->right=NULL;
            current->left=newnode;
        }
        else {
             //if left child is not empty ,traverse to next child
            insert_val(current->left,value);
        }
    }
    else if(value>current->data){
        if(current->right==NULL){
            //if current node doesn't have right child
            //create node and make current right points to it
            node* newnode=new node;
            newnode->data=value;
            newnode->left=NULL;
            newnode->right=NULL;
            current->right=newnode;
        }
        else {
            //if right child is not empty ,traverse to next child
            insert_val(current->right,value);
        }
    }

}
}
void BST::BFS_level_order(node* current){
if(root==NULL) return; //tree is empty
else{
//tree has elements
queue <node*> q; //create queue to store addresses when traversals
q.push(root); //push first node and its root
        while(!q.empty()){
        current=q.front();
        if(current->left!=NULL)
            q.push(current->left); //save address of left node
        if(current->right!=NULL)
            q.push(current->right);//save address of right node
        cout<<current->data<<"\t";
        q.pop();
        }
    }
cout<<endl;
}
node* BST::SEARCH(node* current,int value){
if(current==NULL)
{ //if tree doesn't have any elements
 cout<<"key not exist"<<endl;
 return NULL;
}
if(current->data==value){
    //base case for recursion ,value is found
 cout<<value<<" is found at address "<<current<<endl;
 return current;
}
else if(value < current->data)
current=SEARCH(current->left,value); //traverse left if value is small,save address to current
else if(value > current->data)
current=SEARCH(current->right,value); //traverse left if value is small,save address to current
}
void BST::inorder(node *current){
if(current==NULL)
    return; //out of function if pointer points to null
inorder(current->left); //traverse left first
cout<<current->data<<"\t"; //print value of node
inorder(current->right); //traverse right
}
void BST::preorder(node *current){
if(current==NULL)
    return;
cout<<current->data<<"\t";
preorder(current->left);
preorder(current->right);
}
void BST::postorder(node *current){
if(current==NULL)
    return;
postorder(current->left);
postorder(current->right);
cout<<current->data<<"\t";
}
node* BST::findMin(node* current){
if(current==NULL)
    return NULL; //if tree is empty
else if(current->left==NULL)
    return current; //minimum is left most node that its left point to null
else
return findMin(current->left); //loop recursively to left if has left node
}
node* BST::findMax(node* current){
if(current==NULL)
    return NULL; //if tree is empty
else if(current->right==NULL)
    return current; //max is right most node that its right point to null
else
return findMax(current->right); //loop recursively to right if has left node
}
node* BST::remove_node(node* current,int value){
node *temp;
if(current==NULL)
{ //if tree doesn't have any elements
 return NULL;
}
else if(value < current->data)
current->left=remove_node(current->left,value); //traverse left subtree untill found the value we looking for
//used to link pervious node to the new node we want to put instead of deleted node
else if(value > current->data)
current->right=remove_node(current->right,value); //traverse left if value is small,save address to current
else {
    //entered if found the data we search for
    //current point to node that we want to delete
        temp=current; //store it to temp pointer that will have the address of next node that we want to replace deleted node
if(temp->left ==NULL && temp->right==NULL)
{
//if node has no children ,just make pervious node point to null
  temp=NULL;
  delete current; //delete node that current->data == value
  return temp; //return null and make pervious node point to null
}
else if(temp->left==NULL && temp->right!=NULL)
{
    //if node has only right child
temp=temp->right; //save address of right child to return it to pervious node
delete current; //delete current node
return temp;   //return temp
}
else if(temp->right==NULL &&temp->left!=NULL)
{
    //if node has only left child
temp=temp->left; //save address of left child into temp
delete current;  //delete current node
return temp;      //return temp
}
else {
        //node has two children
 temp=findMin(current->right); //temp has address of minimun node in right subtree to current node
 current->data=temp->data;    //make node that we want to delete has same data to min of right sub tree
 current->right=remove_node(current->right,current->data); //make its right points to the next
}
}
}
int main()
{
BST mytree;
mytree.insert_val(10);
mytree.insert_val(7);
mytree.insert_val(15);
mytree.insert_val(2);
mytree.insert_val(30);
mytree.insert_val(9);
mytree.insert_val(13);
mytree.BFS_level_order();
mytree.SEARCH(30);
mytree.inorder();
mytree.preorder();
mytree.postorder();
cout<<mytree.findMin()->data<<endl;
cout<<mytree.findMax()->data<<endl;
mytree.remove_node(15);
mytree.BFS_level_order();


    return 0;
}
