class Solution {
public:
    int solve(vector<int>& nums,int i,int pi,vector<vector<int>>&dp) {
        int n = nums.size();
        if (i >= n) return 0;
        
        if (dp[i][pi + 1] != -1) return dp[i][pi + 1];

        int take = 0;
        if (pi == -1 || nums[i] > nums[pi]) 
        {
            take = 1 + solve(nums,i + 1,i,dp);
        }

        int nt = solve(nums,i + 1,pi,dp);

        return dp[i][pi + 1] = max(take,nt);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n + 1,-1));
        return solve(nums,0,-1,dp);
    }
};