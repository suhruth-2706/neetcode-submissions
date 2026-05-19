class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto it : s)
        {
            if(isalnum(it))
            {
                str += tolower(it);
            }
        }
        int n = str.size();
        int i = 0,j = n-1;
        while(i <= j)
        {
            if(str[i] != str[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
