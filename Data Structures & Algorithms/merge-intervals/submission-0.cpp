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
};
