class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        
        ListNode* ans = new ListNode(-1); 
        ListNode* a1 = ans;               
        
        while (h1 || h2 || carry) 
        {
            int sum = carry;
            
            if (h1) 
            {
                sum += h1->val;
                h1 = h1->next;
            }
            if(h2) 
            {
                sum += h2->val;
                h2 = h2->next;
            }
            
            carry = sum/10;
            a1->next = new ListNode(sum % 10);
            a1 = a1->next;
        }
        
        return ans->next; 
    }
};