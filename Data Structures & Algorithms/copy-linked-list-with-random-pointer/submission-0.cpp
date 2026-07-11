/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        map<Node*,Node*> m;
        while(temp)
        {
            Node* newnode = new Node(temp->val);
            m[temp] = newnode;
            temp = temp->next;
        }
        temp = head;
        while(temp)
        {
            Node* curr = m[temp];
            curr->next = m[temp->next];
            curr->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }
};