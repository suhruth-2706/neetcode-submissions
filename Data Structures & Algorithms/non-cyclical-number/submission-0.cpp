class Solution {
public:
    int ssquare(int n)
    {
        int ans = 0;
        while(n > 0)
        {
            int rem = n%10;
            ans += (rem*rem);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(n > 1)
        {
            n = ssquare(n);
            if(n == 1)return true;
            if(m.find(n) != m.end())
            {
                return false;
            }
            m[n] = 1;
        }
        return true;
    }
};
