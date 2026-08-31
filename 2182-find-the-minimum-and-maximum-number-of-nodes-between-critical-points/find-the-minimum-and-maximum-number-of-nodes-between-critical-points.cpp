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
class Solution {
public:
    int findLength(ListNode*head){
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len=findLength(head);
        if(len<=2) return {-1,-1};

        vector<int>ans;
        ListNode*prev=head;
        ListNode*temp=head->next;
        int count=2;
        while(temp->next!=NULL){
            if(temp->val<prev->val && temp->val<temp->next->val){
                ans.push_back(count);
            }
            if(temp->val>prev->val && temp->val>temp->next->val){
                ans.push_back(count);
            }
            prev=prev->next;
            temp=temp->next;
            count++;
        }
        if(ans.size()<=1) return {-1,-1};
        int mini=*min_element(ans.begin(),ans.end());
        int maxi=*max_element(ans.begin(),ans.end());
        int maxElement=maxi-mini;

        int minElement=maxElement;
        for(int i=1;i<ans.size();i++){
            minElement=min(minElement,ans[i]-ans[i-1]);
        }
        return {minElement,maxElement};
    }
};