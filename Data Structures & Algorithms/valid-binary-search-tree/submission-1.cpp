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
    unordered_set<int>s;
    vector<int>in;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            in.push_back(root->val);
            s.insert(root->val);
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return is_sorted(in.begin(),in.end()) && s.size() == in.size();

    }
};
