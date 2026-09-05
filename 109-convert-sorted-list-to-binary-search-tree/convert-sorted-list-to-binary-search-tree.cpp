/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode*buildTree(vector<int>&nodes,int startInd,int endInd,int index){
        if(startInd>endInd) return NULL;
        TreeNode*root= new TreeNode(nodes[index]);
        int si=startInd;
        int ei=index-1;
        int ind=si+(ei-si)/2;
        root->left=buildTree(nodes,si,ei,ind);

        int si2=index+1;
        int ei2=endInd;
        int ind2=si2+(ei2-si2)/2;
        root->right=buildTree(nodes,si2,ei2,ind2);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int>nodes;
        ListNode*temp=head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        int mid=nodes.size()/2;
        return buildTree(nodes,0,nodes.size()-1,mid);
    }
};