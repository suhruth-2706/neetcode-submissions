class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i = 0;i<n;i++)
        {
            int curr = 1;
            for(int j = 0;j<n;j++)
            {
                if(j == i)
                continue;
                curr *= nums[j];
            }
            ans[i] = curr;
        }
        return ans;
    }
};
