
class Solution {
public:
    int expand(const string& s, int l, int r)
    {
        while (l >= 0&&r<s.size()&&s[l] == s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(const string& s)
    {
        int n = s.size();
        if (n<=1 || s == string(s.rbegin(), s.rend()))
        {
            return s;
        }
        int st = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int l = expand(s,i,i);
            int r = expand(s,i,i+1);
            int ans = max(l, r);
            if (ans > end - st)
            {
                st = i - (ans - 1)/2;
                end = i + ans/2;
            }
        }
        return s.substr(st, end - st + 1);
    }
};