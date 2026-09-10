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
    int count=0;
    int noOfsubtree(TreeNode*root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        return 1+noOfsubtree(root->left)+noOfsubtree(root->right);
    }
    int sumOfSubtree(TreeNode*root){
        if(root==NULL) return 0;
        //if(root->left==NULL && root->right==NULL) return root->val;
        int left=sumOfSubtree(root->left);
        int right=sumOfSubtree(root->right);
        int noOfNode=noOfsubtree(root);
        int avg=(root->val+left+right)/noOfNode;
        if(root->val==avg) count++;
        return root->val+left+right;
        }
    int averageOfSubtree(TreeNode* root) {
        sumOfSubtree(root);
        return count;
    }
};