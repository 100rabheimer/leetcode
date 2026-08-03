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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //1.base case 
        if(head==NULL || head->next==NULL)
        return head;

        //Dummy node isliye use karte hain taaki beforeNode hamesha exist kare. Agar left = 1 ho, to reverse part list ke head se hi start hota hai. Us case mein beforeNode nahi hota. Dummy node ko beforeNode bana kar hum har case ko ek hi logic se handle kar lete hain

        ListNode* dummy=new ListNode(0);
        dummy->next=head;


        ListNode* beforeNode=dummy;
        for(int i=1;i<left;i++){
            beforeNode=beforeNode->next;//beforenode ko left-1 tk le jao
        }
        ListNode* leftNode=beforeNode->next;

        /*
        dummy    1=beforenode and 2=leftnode
        D->1->2->3->4->5
        */

        //reverse kr rhe hai hmlog yaha pe
        ListNode* prev=NULL;
        ListNode* curr=leftNode;
        ListNode* next=NULL;
        for(int i=0;i<right-left+1;i++)
            {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        //connect things 
        beforeNode->next=prev;
        leftNode->next=curr;

        return dummy->next;

    }
};