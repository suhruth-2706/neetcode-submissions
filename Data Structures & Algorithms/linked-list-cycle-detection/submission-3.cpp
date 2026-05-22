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
    bool hasCycle(ListNode* head) {
        ListNode* sl = head;
        ListNode* fs = head;

        while(sl && fs)
        {
            if(sl->next)
            sl = sl->next;
            else
            {
                return false;
            }
            if(fs->next && fs->next->next)
            fs = fs->next->next;
            else
            {
                return false;
            }
            if(sl == fs)return true;
        }
        return false;

    }
};
