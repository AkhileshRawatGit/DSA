#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* pre;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->pre=NULL;

    }
};

//  Node* convertIntoddl(vector<int>&a){
//     int n=a.size();
//     Node*head=new Node(a[0]);
//     Node*pre=head;
//     for(int i=1;i<n;i++){
//         Node*temp=new Node(a[i]);
//         pre->next=temp;
//         pre=temp;
//     }
//     return pre;
// }

//print the linked list element
void display(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

//print the length of linked list
int getlength(Node* head){
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

//insert at head
void insertAtHead(Node *&head,Node*&tail,int data){
    if(head==NULL){
        Node*temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node*temp=new Node(data);
        temp->next=head;
        head->pre=temp;
        head=temp;
    }
    
}

//insert at tail
void insertAtTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node*temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node*temp=new Node(data);
        temp->pre=tail;
        tail->next=temp;
        tail=temp;
    }
}

//traverse via tail
void display2(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->pre;
    }
}

//insert at any index
void insertAtAnyIndex(Node*&head,Node*&tail,int index,int data){
    if(index==1){
         insertAtHead(head,tail,data);
         return;
        }
    Node*temp=head;
    int cnt=1;
    while(cnt<index-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,data);
        return ;
    }

    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next->pre=newNode;
    temp->next=newNode;
    newNode->pre=temp;
}

//delete node at head, at any index, at tail
void deleteNode(Node*&head,int position){
    if(position==1){
        if(head==NULL) return;
        Node*temp=head;
        head=temp->next;
        temp->next->pre=NULL;
        temp->next=NULL;
        delete(temp);
    }
    else{
        Node*curr=head;
        Node*pree=NULL;
        int cnt=1;
        while(cnt<position){
            pree=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            curr->pre->next=NULL;
            curr->pre=NULL;
            delete(curr);
            return;
        }
        pree->next=curr->next;
        curr->next->pre=pree;
        curr->next=NULL;
        curr->pre=NULL;
        delete(curr);
    }
}


int main(){
    // vector<int>a={12,3,4,5,6};
    // Node*head=convertIntoddl(a);
    // display(head);
    Node* head=NULL;
    Node*tail=NULL;
    cout<<getlength(head);
    cout<<endl;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    display(head);
    cout<<endl;
    insertAtTail(head,tail,20);
    display(head);
    cout<<endl;

    // display2(tail);

    insertAtAnyIndex(head,tail,3,15);
    display(head);
    cout<<endl;

    insertAtAnyIndex(head,tail,1,40);
    display(head);
    cout<<endl;

    insertAtAnyIndex(head,tail,6,30);
    display(head);
    cout<<endl;

    deleteNode(head,1);
    display(head);
    cout<<endl;

    deleteNode(head,3);
    display(head);
    cout<<endl;

    deleteNode(head,4);
    display(head);
    cout<<endl;
    return 0;
}