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
    int getHeight(TreeNode* root)
    {
        if(root==NULL)return 0;

        return max(getHeight(root->left),getHeight(root->right)) + 1;
    }
    void inorder(TreeNode* root,bool &ans)
    {
        if(root)
        {
            inorder(root->left,ans);
            int lh = getHeight(root->left);
            int rh = getHeight(root->right);
            if(abs(lh-rh)>1)ans = false;
            inorder(root->right,ans);
        }
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        if(root == NULL)return true;
        else if(!root->left && !root->right)return true;
        else
        {
            
            inorder(root,ans);
        }
        return ans;
        
    }
};