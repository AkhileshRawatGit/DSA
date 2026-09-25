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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode*result=new ListNode();
        ListNode*temp1=result;
        ListNode*temp2=head;
        while(temp2!=NULL&& temp2->next!=NULL){
            temp1->next=temp2->next;
            temp2->next=temp1->next->next;
            temp1->next->next=temp2;

            temp1=temp2;
            temp2=temp2->next;
        }

        return result->next;
    }
};