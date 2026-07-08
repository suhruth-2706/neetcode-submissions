class Solution {
public:

    bool is_pal(string &s)
    {
        int i = 0;
        int j = s.size() - 1;
        while(i <= j)
        {
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,vector<string>&curr,int j,vector<vector<string>>&ans)
    {
        string temp = "";
        if(j == s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i = j;i<s.size();i++)
        {
            temp += s[i];
            if(is_pal(temp))
            {
                curr.push_back(temp);
                solve(s,curr,i+1,ans);
                curr.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(s,curr,0,ans);
        return ans;
    }
};