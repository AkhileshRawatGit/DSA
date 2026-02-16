#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};
vector<vector<int>> zigzagLevelOrder(Node* root) {
        if (root == NULL)
            return {};
        queue<Node*> q;
        vector<vector<int>> res;
        vector<int> ans;
        q.push(root);
        q.push(NULL);
        while (q.size() > 0) {
            Node* curr = q.front();
            q.pop();
            if (curr == NULL) {
                if (q.size() > 0) {
                    res.push_back(ans);
                    ans.clear();
                    q.push(NULL);
                    continue;
                } else {
                    res.push_back(ans);
                    break;
                }
            }
            ans.push_back(curr->val);
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        int count=0;
        for(auto&i: res){
            if(count%2!=0){
                reverse(i.begin(),i.end());
            }
            count++;
        }
        return res;
    }

static int index=-1;
Node*create(vector<int>node){
    index++;
    if(node[index]==-1) return NULL;
    Node*curr=new Node(node[index]);
    curr->left=create(node);
    curr->right=create(node);
    return curr;
}
int main(){
    vector<int>ans={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node*root=create(ans);
    vector<vector<int>>a=zigzagLevelOrder(root);
    for(auto&i:a){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}