/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findPosition(vector<int>& inorder, int startIn, int endIn, int val) {
        for (int i = startIn; i <= endIn; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }
    TreeNode* buildTreeNode(vector<int>& inorder, vector<int>& postorder,
                            int startIn, int endIn, int index) {
        if (startIn > endIn)
            return NULL;
        TreeNode* root = new TreeNode(postorder[index]);
        int position = findPosition(inorder, startIn, endIn, postorder[index]);
        root->right =
            buildTreeNode(inorder, postorder, position + 1, endIn, index - 1);
        root->left = buildTreeNode(inorder, postorder, startIn, position - 1,
                                   index - (endIn - position) - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeNode(inorder, postorder, 0, inorder.size() - 1,
                             postorder.size() - 1);
    }
};