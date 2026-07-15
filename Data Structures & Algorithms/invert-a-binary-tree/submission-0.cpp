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
    void reverse(TreeNode* r1)
    {
        if(r1==NULL)return;


       
        swap(r1->left,r1->right);

        reverse(r1->left);
        reverse(r1->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        reverse(root);
       
        return root;
    }
};