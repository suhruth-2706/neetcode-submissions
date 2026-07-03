class Solution {
public:
    int solve(vector<int>&nums,int i,int ans,vector<int>&dp)
    {
        int n = nums.size();
        if(i>=n)return ans;

        if(dp[i])return dp[i];
        int pick = nums[i] + solve(nums,i+2,ans,dp);
        int np = solve(nums,i+1,ans,dp);

        ans = max(pick,np);
        dp[i] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        
        int ans = 0;
        vector<int>dp(n,0);
        return solve(nums,0,ans,dp);
        //return ans;

    }
};