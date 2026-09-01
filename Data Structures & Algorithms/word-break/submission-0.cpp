class Solution {
public:
    bool solve(int idx, string& s, vector<string>& wordDict, vector<int>& dp) {
        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (auto& it : wordDict) 
        {
            int len = it.size();

            if(idx + len <= s.size() && s.substr(idx,len) == it) 
            {

                if (solve(idx + len, s, wordDict, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n,-1);

        return solve(0, s, wordDict, dp);
    }
};
