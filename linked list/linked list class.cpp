#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class linkedlist {
    public:
    Node* head;
    Node* tail;
    int size;
    linkedlist(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void insertatend(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void display(){
     Node *temp=head;
     while(temp!=NULL){
        cout<<temp->val;
        temp=temp->next;
     }   
     cout<<endl;
    }
};
int main(){
    linkedlist *ll=new linkedlist();  //{ }
    ll->insertatend(10); //{10->NULL}
    ll->display();
    ll->insertatend(20);//{10->20->NULL}
    ll->display();
    return 0;
}