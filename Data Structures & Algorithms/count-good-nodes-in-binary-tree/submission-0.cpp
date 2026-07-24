/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;
    void preOrder(TreeNode* root,int high)
    {
        if(root)
        {
            high = max(high,root->val);
            if(root->val == high)ans++;
            preOrder(root->left,high);
            preOrder(root->right,high);
        }        
    }
    int goodNodes(TreeNode* root) {
        preOrder(root,-101);
        return ans;    
    }
};
