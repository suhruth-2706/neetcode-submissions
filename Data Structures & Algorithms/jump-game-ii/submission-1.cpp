class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) 
        return 0;

        int jmps = 0;
        int curr = 0;
        int high = 0;

        for(int i = 0;i < n - 1;i++) 
        {
            high = max(high,i + nums[i]);
            if(i == curr) 
            {
                jmps++;
                curr = high;
                if(curr >= n - 1) 
                break;
            }
        }
        return jmps;
    }
};