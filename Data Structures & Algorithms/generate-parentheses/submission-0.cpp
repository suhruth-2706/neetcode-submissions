class Solution {
public:
    void solve(int o,int c,string curr,vector<string>&ans,int n)
    {
        if(o == c && o+c == 2*n)
        {
            ans.push_back(curr);
        }
        if(o<n)
        {
            solve(o+1,c,curr + '(',ans,n);
        }
        if(c < o)
        {
            solve(o,c+1,curr + ')',ans,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,"",ans,n);
        return ans;
    }
};