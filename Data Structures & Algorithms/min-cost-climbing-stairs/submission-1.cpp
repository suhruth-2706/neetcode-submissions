class Solution {
public:
    int solve(int i,vector<int>& cost,vector<int>&dp)
    {
        int n = cost.size();
        if(i >= n)return 0;
        //if(i == n -1)return 0;
        if(dp[i] != -1)return dp[i];
        return dp[i] = min(solve(i+1,cost,dp),solve(i+2,cost,dp)) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
       // dp[n-1] = 0;
        //return min(solve(0,cost,dp),solve(0,cost,dp));
        int ans = solve(0,cost,dp);
        return min(ans,solve(1,cost,dp));
    }
};
