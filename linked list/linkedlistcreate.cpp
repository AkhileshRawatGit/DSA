#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* createNode(int val,Node*head){
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
    return head;
    
}

void traverse(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node * insertAtBegining(Node*head, int val){
    if(head==NULL){
        Node*newNode=new Node(val);
        head=newNode;
    }
    else{
        Node*newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
    return head;
}
Node * insertending(Node*head, int val){
    if(head==NULL){
        Node*newNode=new Node(val);
        head=newNode;
    }
    else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        Node*newNode=new Node(val);
        temp->next=newNode;
    }
    return head;
}
int sizeofll(Node*head){
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
Node* insertAtIndex(Node*head, int val,int ind){
    if(ind==0){
        head=insertAtBegining(head,val);
    }
    else if(ind==sizeofll(head)){
        head=insertending(head,val);
    }
    else{
        Node*temp=head;
        while(ind>1){
            temp=temp->next;
            ind--;
        }
        Node*newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
    
}
int main(){
    Node*head=NULL;
    head=createNode(5,head);
    head=createNode(6,head);
    head=createNode(7,head);
    head=createNode(8,head);
    head=createNode(9,head);
    traverse(head);
    cout<<endl;
    head=insertAtBegining(head,4);
    traverse(head);
    cout<<endl;
    head=insertending(head,10);
    traverse(head);
    cout<<endl;
    head=insertAtIndex(head,1,2);
    traverse(head);
    cout<<endl; 
    return 0;
}