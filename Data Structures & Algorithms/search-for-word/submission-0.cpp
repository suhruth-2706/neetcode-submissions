class Solution {
public:
    bool find(int i, int j, int index, string word, vector<vector<char>>& board, int m, int n)
    {   
        if (index == word.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index] || board[i][j] == '!')
        {
            return false;
        }
        char x = board[i][j];
        board[i][j] = '!';
        bool top = find(i - 1, j, index + 1, word, board, m, n);
        bool down = find(i + 1, j, index + 1, word, board, m, n);
        bool left = find(i, j - 1, index + 1, word, board, m, n);
        bool right = find(i, j + 1, index + 1, word, board, m, n);
        //backtrack
        board[i][j] = x;

        return top || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && find(i, j, 0, word, board, m, n))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
