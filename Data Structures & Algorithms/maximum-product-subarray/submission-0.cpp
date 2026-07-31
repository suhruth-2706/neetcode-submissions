class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int low = 1,high = 1;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            int curr = high*nums[i];
            high = max({curr,nums[i]*low,nums[i]});
            low = min({curr,nums[i]*low,nums[i]});
            ans = max(ans,high);
        }
        return ans;
    }
};
