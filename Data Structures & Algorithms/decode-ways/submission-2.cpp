class Solution {
public:
    int solve(int i, string &s, vector<int>& v) {
        if (v[i] > -1) return v[i];
        if (s[i] == '0') return v[i] = 0;
        int ans = solve(i + 1, s, v);
        if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ans += solve(i + 2, s, v);

        v[i] = ans;
        return v[i];
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> v(n + 1, -1);
        v[n] = 1;
        return solve(0,s,v);
    }
};
