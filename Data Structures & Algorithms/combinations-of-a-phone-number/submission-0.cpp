class Solution {
public:
    vector<string>ans;
    void backtrack(int idx,string &digits,vector<string>&v,string curr)
    {
        int n = digits.size();
        if(curr.size() == n)
        {
            ans.push_back(curr);
            return;
        }
        int di = digits[idx] - '0';
        for(auto it : v[di])
        {
            backtrack(idx + 1,digits,v,curr + it);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)return {};
        vector<string>v(10);
        int x = 97;
        for(int i = 2;i<10;i++)
        {
            if(i == 7 || i == 9)
            {
                v[i] += x;
                x++;
                v[i] += x;
                x++;
                v[i] += x;
                x++;
                v[i] += x;
                x++;
            }
            else
            {
                v[i] += x;
                x++;
                v[i] += x;
                x++;
                v[i] += x;
                x++;
            }
            
        }
        backtrack(0,digits,v,"");
        //cout << v[5];
        return ans;
    }
};
