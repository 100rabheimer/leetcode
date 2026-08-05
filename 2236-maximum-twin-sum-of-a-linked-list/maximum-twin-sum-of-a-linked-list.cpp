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
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow= head;
        while(fast != NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr!=NULL){
            ListNode* nextnode= curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        ListNode* first=head;;
        ListNode* second=prev;
        int ans=0;
        while(second !=NULL){
            ans=max(ans, second->val+first->val);
            first=first->next;
            second=second->next;
        }
        return ans;
    }
};