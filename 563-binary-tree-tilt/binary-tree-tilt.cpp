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
    int grandTotal=0;
    int totalSum(TreeNode*root){
        if(root->left==NULL && root->right==NULL) return root->val;
        int leftSum=0;
        if(root->left){
            leftSum+=totalSum(root->left);
        }
        int rightSum=0;
        if(root->right){
            rightSum+=totalSum(root->right);
        }
        grandTotal+=abs(leftSum-rightSum);
        return root->val+leftSum+rightSum;

    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        totalSum(root);
        return grandTotal;
    }
};