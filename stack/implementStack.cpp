#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
void push(Node*&head,int val){
    if(head==NULL){
        Node*newNode=new Node(val);
        head=newNode;
    }
    else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        Node*newNode=new Node(val);
        temp->next=newNode;
    }
}
int pop(Node*head){
    Node*temp=head;
    if(head->next==NULL){
        int a=head->val;
        head=NULL;
        return a;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    int val=temp->next->val;
    temp->next=NULL;
    return val;
}
int peek(Node*head){
    Node*temp=head;
    if(head->next==NULL){
        return head->val;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp->val;
}
int main(){
    Node*head=NULL;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);
    print(head);
    cout<<endl;
    cout<<pop(head)<<endl;
    print(head);
    cout<<endl;
    cout<<peek(head);
    return 0;
}