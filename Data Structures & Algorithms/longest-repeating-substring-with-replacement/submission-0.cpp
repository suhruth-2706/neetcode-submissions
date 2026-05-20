class Solution {
public:
    int characterReplacement(string s,int k) {
        int ans = 0;
        int curr = 0;
        int j = 0;
        unordered_map<char,int>m;
        for(int i = 0;i<s.size();i++)
        {
            m[s[i]]++;
            curr = max(curr,m[s[i]]);
            while((i - j + 1) - curr > k)
            {
                m[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
