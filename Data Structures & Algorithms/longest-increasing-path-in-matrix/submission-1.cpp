#include <vector>
#include <algorithm>

class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLength = 1; 

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        if(dp[r][c] != -1)return dp[r][c];
        for (int i = 0;i < 4;i++) 
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) 
            {
                maxLength = max(maxLength,1 + dfs(nr, nc, matrix,dp));
            }
        }

        return dp[r][c] = maxLength;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        int overallMax = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for (int i = 0;i < m;i++) 
        {
            for (int j = 0;j < n;j++) 
            {
                overallMax = max(overallMax,dfs(i,j,matrix,dp));
            }
        }

        return overallMax;
    }
};