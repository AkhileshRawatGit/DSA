#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node*next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class linkedlist{
    public:
    node* head;
    node* tail;
    int size;
    linkedlist(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void insertatbeg(int val){
        node*temp=new node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
        size++;

        
    }
    void insertatend(int val){
        node*temp=new node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertatany(int val,int indx){
        if(indx<0 || indx>size) cout<<"Invaild";
        else if(indx==0) insertatbeg(val);
        else if(indx==size) insertatend(val);
        else{
            node*temp=new node(val);
            node*t=head;
            for(int i=1;i<=indx-1;i++){
                t=t->next;
            }
            temp->next=t->next;
            t->next=temp;
            size++;
        }
    }
    void deleteatbeg(){
        if(size==0) cout<<"invalid";
        else if(size>=1){
            head=head->next;
            size--;
        }
    }
    void deleteatend(){
        if(size==0) cout<<"invalid";
        else if(size>=1){
            node*temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }
    }
    void deleteatany(int indx){
        if(indx<0 || indx>size) cout<<"Invaild";
        else if(indx==0) deleteatbeg();
        else if(indx==size-1) deleteatend();
        else{
            node*temp=head;
            for(int i=1;i<=indx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            //temp->next=NULL;
            size--;
        }
    }
    void display(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    linkedlist*ll=new linkedlist();
    ll->insertatbeg(10);
    ll->insertatbeg(30);
    ll->insertatbeg(40);
    ll->display();
    ll->insertatend(50);
    ll->display();
    ll->insertatany(60,2);
    ll->display();
    ll->deleteatbeg();
    ll->display();
    ll->deleteatend();
    ll->display();
    ll->deleteatany(2);
    ll->display();
    cout<<ll->size;

    return 0;
}