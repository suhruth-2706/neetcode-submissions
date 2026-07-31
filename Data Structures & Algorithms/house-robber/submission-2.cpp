class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp)
    {
        int n = nums.size();
        if(idx >= n)return 0;
        if(idx == n-1)return nums[idx];
        if(dp[idx] != -1)return dp[idx];
        int pick = nums[idx] + solve(idx+2,nums,dp);
        int np = solve(idx + 1,nums,dp);
        return dp[idx] = max(pick,np);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};
