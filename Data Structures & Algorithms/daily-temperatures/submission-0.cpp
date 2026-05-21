class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i = 0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({temp[i], i});
                continue;
            }
            while(!st.empty() && temp[i] > st.top().first)
            {
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i] , i});
        }
        return ans;
    }
};
