class Solution {
public:
    vector<vector<int>>ans;
    void subset(int idx,vector<int>&nums,vector<int>temp)
    {
        int n = nums.size();
        if(idx >= n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subset(idx + 1,nums,temp);
        temp.pop_back();
        subset(idx + 1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subset(0,nums,{});
        return ans;
    }
};
