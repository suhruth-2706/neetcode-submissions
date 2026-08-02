class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) 
    {
        int m = s1.size();
        int n = s2.size();
        if(i + j == s3.size() && (i == m && j == n)) return true; 
        if(dp[i][j] != -1) return dp[i][j];

        bool ok = false;
        if(i < m && s1[i] == s3[i + j])
            ok = solve(s1,s2,s3,i + 1,j,dp);
        if(!ok && j < n && s2[j] == s3[i + j])
            ok = solve(s1,s2,s3,i,j + 1,dp);

        return dp[i][j] = ok;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};
