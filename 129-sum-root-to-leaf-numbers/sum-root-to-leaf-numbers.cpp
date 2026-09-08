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
    void sumString(TreeNode*root, string &s,vector<string>&ans){
        if(root==NULL){
            return;
        }
        char ch=(root->val)+'0';
        //left 
        s+=ch;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            s.pop_back();
            return;
        }
        
        sumString(root->left, s,ans);
        sumString(root->right,s,ans);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        vector<string>ans;
        string s="";
        sumString(root,s,ans);
        int res=0;
        for(int i=0;i<ans.size();i++){
            int a=stoi(ans[i]);
            res+=a;
        }
        return res;
    }
};