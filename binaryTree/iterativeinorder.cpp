#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        left=right=nullptr;
    }
};
vector<int> itrative(Node*root){
    stack<Node*>st;
    vector<int>ans;
    stack<bool>flag;
    st.push(root);
    flag.push(0);
    while(st.size()>0){
        Node*curr=st.top();
        st.pop();
        bool a=flag.top();
        flag.pop();
        if(a==0){
            if(curr->right!=NULL){
                st.push(curr->right);
                flag.push(0);
            }
            st.push(curr);
            flag.push(1);
            if(curr->left!=NULL){
                st.push(curr->left);
                flag.push(0);
            }
        }
        else{
            ans.push_back(curr->data);
        }
    }
    return ans;
}
static int ind=-1;
Node* create(vector<int>ans){
    ind++;
    if(ans[ind]==-1) return NULL;
    Node*curr=new Node(ans[ind]);
    curr->left=create(ans);
    curr->right=create(ans);
    return curr;
}
int main(){
    vector<int>ans={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node*root=create(ans);
    vector<int>res=itrative(root);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}