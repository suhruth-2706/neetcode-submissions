class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(i > ans)return false;
            if(i <= ans && ans <= i + nums[i])
            {
                ans = i + nums[i];
            }
        }
        return ans >= n - 1;
    }
};
