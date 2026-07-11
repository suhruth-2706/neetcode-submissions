/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* rev(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode* m = findMiddle(head);

        
        ListNode* temp = rev(m->next);

        
        m->next = NULL;

        
        ListNode* curr = head;

        while (curr && temp) 
        {
            ListNode* front1 = curr->next;
            ListNode* front2 = temp->next;

            curr->next = temp;
            temp->next = front1;

            curr = front1;
            temp = front2;
        }
    }
};
