class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curr = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        { 
            curr += nums[i];
            ans = max(ans,curr);
            if(curr < 0)
            {
                curr = 0;
            }

        }
        return ans;
    }
};
