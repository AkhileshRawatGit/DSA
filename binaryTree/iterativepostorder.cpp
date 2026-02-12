#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
static int ind=-1;
Node*create(vector<int>ans){
    ind++;
    if(ans[ind]==-1) return NULL;
    Node*root=new Node(ans[ind]);
    root->left=create(ans);
    root->right=create(ans);
    return root;
}

vector<int> iterative(Node*root){
    vector<int>ans;
    stack<Node*>st;
    st.push(root);
    while(st.size()>0){
        root=st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->left!=NULL){
            st.push(root->left);
        }
        if(root->right!=NULL){
            st.push(root->right);
        }
    }
    return ans;
}
int main(){
    vector<int>ans={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node*root=create(ans);
    vector<int>res=iterative(root);
    reverse(res.begin(),res.end());
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}