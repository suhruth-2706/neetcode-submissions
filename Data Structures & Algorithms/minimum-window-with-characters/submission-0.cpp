class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int len = t.size();

        if(len > n) return "";
        if(len == n && s == t) return s;

        vector<int> freq(128, 0);

        for(char c : t) {
            freq[c]++;
        }

        int cnt = t.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        int si = 0;

        while(j < s.size()) {

            if(freq[s[j++]]-- > 0) {
                cnt--;
            }

            while(cnt == 0) {

                if(j - i < ans) {
                    ans = j - i;
                    si = i;
                }

                if(freq[s[i++]]++ == 0) {
                    cnt++;
                }
            }
        }

        return ans == INT_MAX ? "" : s.substr(si, ans);
    }
};