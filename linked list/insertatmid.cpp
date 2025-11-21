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
class linkedlist{
    public:
    Node* head;
    Node* tail;
    int size;
    linkedlist(){
        head=NULL;
        tail=NULL;
        size=0;
    }
        void insertattail(int val){
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
    void insertathead(int val){
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
            insertathead(val);
        }
        else if(idex==size){
            insertattail(val);
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
        cout<<temp->val<<" ";
        temp=temp->next;
     }   
     cout<<endl;
    }
    int get(int v){
        if(v<0 || v>=size) return -1;
        else if(v==0) return head->val;
        else if(v==size-1) return tail->val;
        else {
            Node* temp=head;
            for(int i=1;i<=v;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }
    void deleteathead(){
        if(size==0) cout<<"list is empty";
        else if(size>=1){
            head=head->next;
            size--;
        }
    }
    void deleteatend(){
        if(size==0) cout<<"list is empty";
        else if(size>=1){
            Node*temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }
    }

    void deleteatmid(int indx){
        if(indx<0 || indx>size){
            cout<<"Invalid"<<endl;
        }
        else if(indx==0) deleteathead();
        else if(indx==size-1){
            deleteatend();
        }
        else{
            Node*temp=head;
            for(int i=1;i<=indx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            // temp->next=NULL;
            size--;
        }
    }
};
int main(){
    linkedlist* ll=new linkedlist();
    int val;
    cin>>val;
    ll->insertattail(10);
    ll->insertattail(20);
    ll->insertattail(30);
    ll->insertattail(40);
    ll->insertattail(50);
    ll->display();
    ll->insertathead(60);
    ll->insertathead(30);
    ll->insertathead(40);
    ll->display();
    ll->insertatany(70,2);
    ll->display();
    //cout<<ll->get(val);
    ll->deleteathead();
    ll->display();
    ll->deleteatend();
    ll->display();
    ll->deleteatmid(7);
    ll->display();
    cout<<ll->size;
}