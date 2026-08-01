class Solution {
public:
    int lcs(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        int m = s1.size();
        int n = s2.size();
        if(i == m || j == n)return 0;
        int take = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j])
        {
            take = 1 + lcs(i + 1,j + 1,s1,s2,dp);
        }
        int ft = lcs(i + 1,j,s1,s2,dp);
        int lt = lcs(i,j+1,s1,s2,dp);
        return dp[i][j] = max({take,ft,lt});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return lcs(0,0,text1,text2,dp);
    }
};
