#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
};
unordered_map<TreeNode*,TreeNode*>mp;
    void allparent(TreeNode*root){
        if(root==NULL) return;
        if(root->left) mp[root->left]=root;
        allparent(root->left);
        if(root->right) mp[root->right]=root;
        allparent(root->right);
    }
    TreeNode* findNode(TreeNode*root,int start){
        if(root == NULL) return NULL;
        if(root->val == start) 
            return root;

        TreeNode* left = findNode(root->left, start);
        if(left != NULL) 
            return left;
        return findNode(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        allparent(root);
        TreeNode*temp=findNode(root,start);


        //burn the tree
        int count=0;
        queue<TreeNode*>q;
        unordered_set<int>st;
        q.push(temp);
        st.insert(temp->val);
        while(q.size()>0){
            int n=q.size();
            while(n--){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left && !st.count(curr->left->val)){
                    q.push(curr->left);
                    st.insert(curr->left->val);
                }
                if(curr->right&& !st.count(curr->right->val)){
                    q.push(curr->right);
                    st.insert(curr->right->val);
                }
                if(mp[curr]!=NULL&&!st.count(mp[curr]->val)){
                    q.push(mp[curr]);
                    st.insert(mp[curr]->val);
                }
            }
        count++;
        }
        return count-1;           
    }
static int index=-1;
TreeNode*create(vector<int>node){
    index++;
    if(node[index]==-1) return NULL;
    TreeNode*curr=new TreeNode(node[index]);
    curr->left=create(node);
    curr->right=create(node);
    return curr;
}
int main(){
    vector<int>ans={1,5,-1,4,9,-1,-1,2,-1,-1,3,10,-1,-1,6,-1,-1};
    TreeNode*root=create(ans);
    cout<<amountOfTime(root,3);
    return 0;
}