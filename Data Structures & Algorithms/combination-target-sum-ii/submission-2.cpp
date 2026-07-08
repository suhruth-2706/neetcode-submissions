class Solution {
public:
    vector<vector<int>> ans;

    void csum(int i,vector<int>& candidates,int target,vector<int>& temp) 
    {
        int n = candidates.size();

        if (target == 0) 
        {
            ans.push_back(temp);
            return;
        }

        if (i >= n || target < 0)
            return;

        
        temp.push_back(candidates[i]);
        csum(i + 1,candidates,target - candidates[i],temp);
        temp.pop_back();

        
        int j = i + 1;
        while (j < n && candidates[j] == candidates[i])
            j++;

        csum(j,candidates,target,temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<int> temp;
        csum(0,candidates,target,temp);

        return ans;
    }
};