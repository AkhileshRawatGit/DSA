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
void display(node*head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
void deletenode(node*head,node* target){
        node*temp=head;
        while(temp->next!=target){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
int main()
{
    node *a=new node(10);
    node *b=new node(20);
    node *c=new node(30);
    node *d=new node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    //node*head=a;
    display(a);
    deletenode(a,a);
    display(a);
    return 0;   
}
