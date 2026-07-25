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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         // Step 1: Find length
        int len = 0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        // Step 2: Position from beginning
        int pos = len - n;

        // Step 3: Delete first node
        if(pos == 0)
        {
            return head->next;
        }

        // Step 4: Reach previous node
        temp = head;

        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        // Step 5: Delete node
        temp->next = temp->next->next;

        return head;
    }
};