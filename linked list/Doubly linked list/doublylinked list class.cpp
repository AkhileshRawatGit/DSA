#include<iostream>
using namespace std;

//class of doubly linked list
class Node{
    public:
    int val;
    Node*pre;
    Node*next;
    Node(int val){
        this->val=val;
        this->pre=pre;
        this->next=next;

    }
};

class doubly{ //user defined data structure
    public:
    Node*head;
    Node*tail;
    int size;
    doubly(){
        head=NULL;
        tail=NULL;
        size=0;

    }
    void insertathead(int val){
        Node*temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head->pre=temp;
            head=temp;
        }
        size++;
    }
    void insertattail(int val){
        Node*temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->pre=tail;
            tail=temp;
        }
        size++;
    }
    void insertatindex(int val,int index){
        if(index<0 || index>size) cout<<"Invalid!!!";
        else if(index==0) insertathead(val);
        else if(index==size) insertattail(val);
        else{
            Node*emp=new Node(val);
            Node*temp=head;
            for(int i=1;i<=index-1;i++){
                temp=temp->next;
            }
            emp->next=temp->next;
            //temp->next->pre=temp;
            temp->next=emp;
            
            emp->pre=temp;
            emp->next->pre=emp;
            size++;
        }

    }
    void deleteathead(){
        if(size==0) cout<<"List is empty";
        //Node*temp=head;
        head=head->next;
        if(head!=NULL) head->pre=NULL;
        if(head==NULL) tail=NULL;
        size--;
    }
    void deleteattail(){
        if(size==0) cout<<"List is empty";
        else if(size==1) deleteathead();
        else{
            Node* temp=head;
            temp=tail->pre;
            tail=temp;
            temp->next=NULL;
            //tail=temp;
            //temp->next=NULL;
            size--;
        }
    }
    void deleteatindex(int index){
        if(index<0 || index>size) cout<<"Invalid!!!";
        else if(index==0) deleteathead();
        else if(index==size-1) deleteattail();
        else{
            if(index<size/2){
            Node*temp=head;
            for(int i=1;i<index;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            temp=temp->next->pre;
            size--;
            }
            else{
                Node*temp=tail;
                for(int i=1;i<=size-index;i++){
                    temp=temp->pre;

                }
                temp->next=temp->next->next;
                temp=temp->next->pre;
            size--;
            }
        }
    }
    int getval(int index){
        if(index<0||index>size) return -1;
        else if(index==0) return head->val;
        else if(index==size-1) return tail->val;
        else{
            if(index<size/2){
                cout<<"akhil";
                Node*temp=head;
            for(int i=1;i<=index;i++){
                temp=temp->next;
            }
            return temp->val;
            }
            else{
                Node*temp=tail;
                cout<<"Rawat";
                for(int i=1;i<size-index;i++){
                    temp=temp->pre;
                }
                return temp->val;
            }
        }
    }
    void display(){
        Node*temp=head;
        while(temp){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }

};
int main(){
    doubly *dd=new doubly();
    dd->insertattail(10);
    dd->insertattail(20);
    dd->insertattail(30);
    dd->insertathead(5);
    dd->insertattail(40);
    //dd->display();
    //cout<<endl;
    dd->insertatindex(60,2);
    //dd->display();
    //cout<<endl;
    //dd->deleteathead();
    //dd->display();
    //cout<<endl;
    //dd->deleteattail();
    //dd->display();
    //cout<<endl;
    //dd->deleteatindex(2);
    dd->display();
    //cout<<endl;
    //cout<<dd->size;
    cout<<endl;
    cout<<dd->getval(4);
    return 0;
}