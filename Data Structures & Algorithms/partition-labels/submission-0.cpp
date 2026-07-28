class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1;i<n;i++)
        {
            int x = ans.back()[0];
            int y = ans.back()[1];
            ans.pop_back();
            if(y >= intervals[i][0])
            {
                int a = min(x,intervals[i][0]);
                int b = max(y,intervals[i][1]);
                ans.push_back({x,b});
            }
            else
            {
                ans.push_back({x,y});
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    vector<int> partitionLabels(string s) {
        map<char,int>m,m1;
        int n = s.size();
        int i = 0;
        for(auto it : s)
        {
            if(!m.count(it))m[it] = i + 1;
            else
            m[it] = min(m[it],i + 1);
            m1[it] = max(m1[it],i + 1);
            i++;
        }
        
        vector<vector<int>>v;
        for(auto it : m)
        {
            v.push_back({it.second,m1[it.first]});
        }
        //sort(v.begin(),v.end());
        v = merge(v);
        vector<int>ans;
        for(auto it : v)
        {
            ans.push_back(it[1] - it[0] + 1);
        }
        return ans;
        return {};
    }
};