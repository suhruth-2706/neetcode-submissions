class Solution {
public:
    int ans = 0;
    
    int calc(TreeNode* root) 
    {
        if (!root) 
        return 0;
        
        int l = calc(root->left);
        int r = calc(root->right);
        
        ans = max(ans,l + r);
        
        return max(l,r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        calc(root);
        return ans;
    }
};