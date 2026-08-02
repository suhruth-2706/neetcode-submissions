class Solution {
public:

    int solve(int idx,string& s,string& t,string curr,map<pair<int,string>,int>&dp)
    {
        int n = s.size();
        if(idx >= n)
        {
            return dp[{idx,curr}]= curr == t ? 1 : 0;
        }
        else if(dp.count({idx,curr}))
        {
            return dp[{idx,curr}];
        }
        else if(idx < n)
        {
            int take = solve(idx + 1,s,t,curr + s[idx],dp);
            int nt = solve(idx + 1,s,t,curr,dp);
            return dp[{idx,curr}] = nt + take;
        }
        return 0;
        
    }
    int numDistinct(string s, string t) {
        map<pair<int,string>,int>dp;
        return solve(0,s,t,"",dp);
    }
};
