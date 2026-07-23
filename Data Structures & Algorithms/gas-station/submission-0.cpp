class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int gsum = accumulate(gas.begin(),gas.end(),0);
        int csum = accumulate(cost.begin(),cost.end(),0);
        if(csum > gsum)return -1;
        int curr = 0;
        int n = gas.size();
        for(int i = 0;i<n;i++)
        {
            curr += gas[i] - cost[i];
            if(curr < 0)
            {
                curr = 0;
                ans = (i+1)%n;
            }
        }
        return ans;
    }
};
