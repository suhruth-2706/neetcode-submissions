class Solution {
public:

    int func(vector<int>& piles, int k)
    {
        int ans = 0;
        for(int i = 0;i<piles.size();i++)
        {
            ans += (piles[i] + k - 1)/k ;
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int curr = func(piles, mid);
            if(curr <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};