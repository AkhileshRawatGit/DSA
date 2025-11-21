#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
    }
};
    void insertionatfirst(Node* &head,int val){

        Node* new_node=new Node(val);
        new_node->next=head;
        head = new_node;
    }
    void insertatlast(Node* &head,int val){
        Node* new_node=new Node(val);
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next= new_node;
    }
    void display(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
int main(){
    Node* head=NULL;
    insertionatfirst(head,2);
    display(head);
    insertionatfirst(head,3);
    display(head);
    insertatlast(head,4);
    display(head);

}