#include<iostream>
using namespace std;
class Node{           //linked list node proper
    public:
    int val;
    Node* next;
    //constructor 
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
void link(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->val<<endl;
        temp=temp->next;
    }
}
//print linked list using recursion
void display(Node* head){
    if(head==NULL){
        return ;
    }
    display(head->next);
    cout<<head->val<<endl;
}
int size(Node *head){
    Node* temp= head;
    int n=0;
    while(temp!=NULL){
        //cout<<temp->val<<endl;
        temp=temp->next;
        n++;
    }
    return n;
}
int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    // Node *temp=a;
    // cout<<&temp<<endl;
    // cout<<temp<<endl;
    // cout<<a;
    link(a);
    display(a);
    cout<<size(a);
    return 0;
}