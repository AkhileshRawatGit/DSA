#include<iostream>
using namespace std;
class Node{           //linked list node proper
    public:
    int val;
    Node* next;
    //constructor 
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    // formint ll
    a.next=&b;
    b.next=&c;
    c.next=&d;

    // print the value of d with the help of a
    // cout<<(a.next)<<endl;
    // cout<<&b<<endl;
    // cout<<(((a.next)->next)->next)->val<<endl;
    // cout<<(*(*(*(a.next)).next).next).val<<endl;

    // Node temp=a;
    // while(temp.next!=NULL){
    //     cout<<temp.val;
    //     temp=*(temp.next);
    // }
    Node temp=a;
    while(1){
        cout<<temp.val;
        if(temp.next==NULL) break;
        temp=*(temp.next);
    }




    //worst method

    /* Node n;
    n.val=10;
    Node b;
    b.val=20;
    Node c;
    c.val=30;
    n.next=&b;
    b.next=&c;
    c.next=NULL;
    cout<<n.val;
    cout<<b.val;
    cout<<c.val; */
    return 0;
}