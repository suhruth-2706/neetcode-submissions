class Solution {
public:
    int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        int n = coins.size();
        if(i >= n)return abs(1e9);
        if(amount == 0)return 0;
        //if(coins[i] == amount)return 1;
        
        int curr = abs(1e9);
        if(dp[i][amount] != -1)return dp[i][amount];
        if(coins[i] <= amount)
        {
            int res = solve(i,coins,amount-coins[i],dp);
            if(res != 1e9)curr = 1+res;
        }
        int rem = solve(i + 1,coins,amount,dp);
        return dp[i][amount] = min(curr,rem);;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
        int ans = solve(0,coins,amount,dp);
        return ans != 1e9 ? ans : -1;
    }
};
