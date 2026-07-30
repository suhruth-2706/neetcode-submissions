class Solution {
public:
    string addLargeNumbers(const string& num1, const string& num2) {
        string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry > 0) 
        {
            int sum = carry;
            if(i >= 0) 
            {
                sum += num1[i] - '0';
                i--;
            }
            if(j >= 0) 
            {
                sum += num2[j] - '0';
                j--;
            }
            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<string> eachres;
        
        for (int i = num2.size() - 1;i >= 0;i--) 
        {
            string curr = "";
            int carry = 0;
            int x = num2[i] - '0';

            int req0 = num2.size() - 1 - i;
            for(int k = 0;k < req0;k++) 
            {
                curr += '0';
            }

            for(int j = num1.size() - 1;j >= 0;j--) 
            {
                int prod = num1[j] - '0';
                prod *= x;
                prod += carry;
                carry = prod / 10;
                curr += (prod % 10) + '0';
            }

            if (carry) 
            {
                curr += (carry + '0');
            }

            reverse(curr.begin(), curr.end());
            eachres.push_back(curr);
        }

        string res = "";
        for (const auto& it : eachres) 
        {
            res = addLargeNumbers(it, res);
        }
        return res;
    }
};
