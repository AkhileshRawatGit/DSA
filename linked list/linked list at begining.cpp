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
    void insertatbed(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertatany(int val,int idex){
        //Node* temp=new Node(val);
        if(idex<0 || idex>size){
            cout<<"Invalid"<<endl;
        }
        else if(idex==0){
            insertatbed(val);
        }
        else if(idex==size){
            insertatend(val);
        }
        else{
            Node *t=new Node(val);
            Node* temp=head;
            for(int i=1;i<=idex-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
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
    ll->insertatbed(30);
    ll->display();
    ll->insertatbed(40);
    ll->display();
    cout<<ll->size;
    return 0;
}