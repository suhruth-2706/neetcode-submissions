class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>>v;
        for(int i = 0;i<n;i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        stack<double>st;
        for(int i = 0;i<n;i++)
        {
            int cp = v[i].first;
            int cs = v[i].second;
            double time = (double)(target - cp)/(cs);
            if(st.empty() || st.top() < time)
            {
                st.push(time);
            }
        }
        return st.size();
    }
};