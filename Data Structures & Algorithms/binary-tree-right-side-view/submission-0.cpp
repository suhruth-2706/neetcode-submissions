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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int>level;
            int n = q.size();
            while(n--)
            {
                level.push_back(q.front()->val);
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);

                q.pop();
                
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>level = levelOrder(root);
        vector<int>ans;
        for(auto it : level)
        {
            ans.push_back(it.back());
        }
        return ans;
    }
};
