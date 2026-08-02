class Solution {
public:
    int solve(int idx,vector<int>&nums,int target,int curr,vector<vector<int>>&dp,int sum)
    {
        int n = nums.size();
        if(target == curr && idx >= n)return 1;
        if(idx >= n)return 0;
        int offset = curr + sum;
        if(dp[idx][offset] != -1)
        {
            return dp[idx][offset];
        }

        int add = solve(idx + 1,nums,target,curr + nums[idx],dp,sum);
        int sub = solve(idx + 1,nums,target,curr - nums[idx],dp,sum);
        return dp[idx][offset] = sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return solve(0,nums,target,0,dp,sum);
    }
};
