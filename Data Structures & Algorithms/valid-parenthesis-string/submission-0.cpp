class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        for(auto it : s)
        {
            if(it == '(' || it == '*')open++;
            else open--;
            
            if(0 > open)return false;
        }
        int n = s.size();
        for(int i = n-1;i>=0;i--)
        {
            if(s[i] == ')' || s[i] == '*')close++;
            else
            close--;
            if(close < 0)return false;
        }
        return true;
    }
};
