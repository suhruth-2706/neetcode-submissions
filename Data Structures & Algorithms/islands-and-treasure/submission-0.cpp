class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        while(!q.empty())
        {
            
            auto [row,col] = q.front();
            q.pop();
            //if(row + 1 < m)
            for(auto it : dirs)
            {
                int nr = row + it.first;
                int nc = col + it.second;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&grid[nr][nc] == INT_MAX)
                {
                    grid[nr][nc] = 1 + grid[row][col];
                    q.push({nr,nc});
                }
            }
        }

    }
};
