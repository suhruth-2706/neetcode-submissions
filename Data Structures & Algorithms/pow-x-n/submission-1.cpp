class Solution {
public:
    double myPow(double x, int n) {
        //return pow(x,n);
        if(x == 0)return 0;
        double ans = 01.0;
        if(n > 0)
        {
            while(n--)
            {
                ans *= x;
            }
        }
        else
        {
            while(n != 0)
            {
                ans /= x;
                n++;
            }
        }
        
        return ans;
    }
};
