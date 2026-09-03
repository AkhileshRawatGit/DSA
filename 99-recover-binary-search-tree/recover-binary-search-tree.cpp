/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode*root,TreeNode*&a,TreeNode*&b,int val1,int val2){
        if(root==NULL) return ;
        if(root->val==val1) a=root;
        if(root->val==val2) b=root;
        traverse(root->left,a,b,val1,val2);
        traverse(root->right,a,b,val1,val2);
        
    }
    void inorder(TreeNode*root, vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int a=ans[0];
        int b=ans[ans.size()-1];
        for(int i=1;i<ans.size();i++){
            if(ans[i]<a) break;
            else a=ans[i];
        }
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i]>b) break;
            else b=ans[i];
        }
        TreeNode*d1=root;
        TreeNode*d2=root;
        traverse(root,d1,d2,a,b);
        swap(d1->val,d2->val);
    }
};