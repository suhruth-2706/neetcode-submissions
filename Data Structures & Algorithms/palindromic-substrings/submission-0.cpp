class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<bool>>&dp,vector<vector<bool>>&vis){
        if(i >= j)return true;
        if(vis[i][j])return dp[i][j];
        vis[i][j] = true;
        if(s[i] != s[j])return dp[i][j] = false;

        return dp[i][j] = solve(i + 1,j -1,s,dp,vis);
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        int ans = n;
        for(int i = 0;i<n;i++)
        {
            for(int j = i + 1;j<n;j++)
            {
                if(solve(i,j,s,dp,vis))ans++;
            }
        }
        return ans;
    }
};
