#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*pre;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->pre=NULL;

    }

};
void display(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void displayrec(Node*head){
    if(head==NULL) return ;
    //cout<<head->data<<"->";
    displayrec(head->next);
    cout<<head->data<<"->";
    //cout<<"NULL";
}

void displayrev(Node*tail){
    while(tail){
        cout<<tail->data<<"->";
        tail=tail->pre;
    }
    cout<<"NULL";
}

int main(){
    Node*a=new Node(100);
    Node*b=new Node(200);
    Node*c=new Node(300);
    Node*d=new Node(400);
    a->next=b;
    b->next=c;
    c->next=d;
    d->pre=c;
    c->pre=b;
    b->pre=a;
    //a->pre=NULL;
    display(a);
    cout<<endl;
    displayrec(a);
    cout<<endl;
    displayrev(d);
    return 0;
}