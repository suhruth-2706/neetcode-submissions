class Solution {
public:
    set<vector<int>>ans;
    void csum(int i,vector<int>& candidates, int target,vector<int>temp)
    {
        int n = candidates.size();
        if(target == 0)ans.insert(temp);
        if(i >= n || target < 0)return;
        if(candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            csum(i,candidates,target-candidates[i],temp);
            temp.pop_back();
        }
        //temp.pop_back();
        if(i + 1 < n)
        {
            csum(i+1,candidates,target,temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        csum(0,candidates,target,temp);
        return vector<vector<int>>(ans.begin(), ans.end());    
    }
};