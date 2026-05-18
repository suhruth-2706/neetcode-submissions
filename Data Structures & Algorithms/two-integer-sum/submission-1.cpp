class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        int i = 0;
        for(auto it : nums)
        {
            m[it] = i;
            i++;
        }
        i = 0;
        for(auto it : nums)
        {
            int req = target - it;
            if(m.find(req) != m.end() && m[req] != i)return {i,m[req]};
            i++;
        }
        return {};
    }
};
