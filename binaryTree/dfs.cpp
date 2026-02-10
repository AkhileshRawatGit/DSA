#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }  
};
void preoder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preoder(root->left);
    preoder(root->right);
}
void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(Node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
static int ind=-1;
Node* create(vector<int>tree){
        ind++;
        if(tree[ind]==-1) return NULL;
        Node* root=new Node(tree[ind]);
        root->left=create(tree);
        root->right=create(tree);
        return root;
    }
int main(){
    vector<int>tree={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node*root=create(tree);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    inorder(root);
    cout<<endl;
    preoder(root);
    cout<<endl;
    postorder(root);
    return 0;
}