class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>res = {0,0,0};
        for(auto it : triplets)
        {
            if(it[0] <= target[0] && it[1] <= target[1] && it[2] <= target[2])
            {
                res[0] = max(res[0],it[0]);
                res[1] = max(res[1],it[1]);
                res[2] = max(res[2],it[2]);
            }
        }
        return res == target;
    }
};