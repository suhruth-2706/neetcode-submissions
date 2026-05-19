class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int curr= 0;
        unordered_map<int,int>m;
        for(auto it : nums)
        {
            m[it]++;
        }
        for(auto it : nums)
        {
            if(m.find(it - 1) == m.end())
            {
                curr = 1;
                while(m.find(it + curr) != m.end())
                curr++;

                ans = max(ans,curr);
            }
            
        }
        return ans;
    }
};
