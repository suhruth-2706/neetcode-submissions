class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp,int end)
    {
        int n = nums.size();
        if(idx > end)return 0;
        if(idx == end)return nums[idx];
        if(dp[idx] != -1)return dp[idx];
        int pick = nums[idx] + solve(idx+2,nums,dp,end);
        int np = solve(idx + 1,nums,dp,end);
        return dp[idx] = max(pick,np);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>dp1(n,-1),dp2(n,-1);
        return max(solve(0,nums,dp1,n-2),solve(1,nums,dp2,n-1));
    }
};
