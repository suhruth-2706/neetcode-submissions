class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(),digits.end());
        for(auto &it : digits)
        {
            it = it+carry;
            if(it >= 10)
            {
                carry = it/10;
                it = it%10;
            }
            else
            {
                carry = it/10;
            }
        }
        if(carry)
        {
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
