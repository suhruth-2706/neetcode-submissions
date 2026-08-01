class Solution {
public:
    bool solve(int idx,vector<int>&nums,int curr,int rem,vector<vector<bool>>&dp,vector<vector<bool>>&vis)
    {
        int n = nums.size();
        if(idx >= n)return false;
        if(curr == rem)return true;
        if(vis[idx][curr])
        {
            return dp[idx][curr];
        }
        vis[idx][curr] = true;
        bool take = solve(idx + 1,nums,curr + nums[idx],rem - nums[idx],dp,vis);
        bool nt = solve(idx + 1,nums,curr,rem,dp,vis);
        return dp[idx][curr] = take || nt;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        vector<vector<bool>>vis(n+1,vector<bool>(sum+1,false));
        return solve(0,nums,0,sum,dp,vis);
    }
};
