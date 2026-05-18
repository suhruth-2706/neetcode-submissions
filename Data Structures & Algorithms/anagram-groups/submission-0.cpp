class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>res;
        for(auto it : strs)
        {
            string s = it;
            sort(it.begin(),it.end());
            res.push_back({it,s});
        }
        map<string,vector<string>>m;
        for(auto it : res)
        {
            m[it.first].push_back(it.second);
        }
        vector<vector<string>>ans;
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
