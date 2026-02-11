#include<iostream>
#include<vector>
#include<queue>
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
static int ind=-1;
Node* create(vector<int>tree){
    ind++;
    if(tree[ind]==-1) return NULL;
    Node* root=new Node(tree[ind]);
    root->left=create(tree);
    root->right=create(tree);
    return root;
}
void levelOrder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node*val=q.front();
        q.pop();
        if(val==NULL){
            if(q.size()>0){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout<<val->data<<" ";
        if(val->left!=NULL){
            q.push(val->left);
        }
        if(val->right!=NULL){
            q.push(val->right);
        }
    }
}
int main(){
    vector<int>ans={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node*root=create(ans);
    levelOrder(root);

    return 0;
}