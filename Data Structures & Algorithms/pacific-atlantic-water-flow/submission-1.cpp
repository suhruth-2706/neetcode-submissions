class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights,vector<vector<bool>>& vis) 
    {
        int m = heights.size();
        int n = heights[0].size();

        vis[i][j] = true;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        for (int k = 0;k < 4;k++) 
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;

            if (vis[ni][nj])
                continue;

            if (heights[ni][nj] >= heights[i][j])
                dfs(ni,nj,heights,vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>>pac(m,vector<bool>(n,false));
        vector<vector<bool>>atl(m,vector<bool>(n,false));

        for (int i = 0;i < m;i++)
            dfs(i,0,heights,pac);

        for (int j = 0;j < n;j++)
            dfs(0,j,heights,pac);

        for (int i = 0;i < m;i++)
            dfs(i,n - 1,heights,atl);

        for (int j = 0; j < n; j++)
            dfs(m - 1,j,heights,atl);

        vector<vector<int>> ans;

        for (int i = 0;i < m;i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};