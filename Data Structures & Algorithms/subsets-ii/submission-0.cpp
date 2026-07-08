class Solution {
public:
    set<vector<int>>ans;
    void solve(int i,vector<int>&nums,vector<int>temp)
    {
        int n = nums.size();
        if(i >= n)
        {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums,{});
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
