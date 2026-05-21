class Solution {
public:
    bool binary_search(vector<int>v,int target)
    {
        int low = 0;
        int high = v.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(v[mid] == target)return true;
            else if(v[mid]>target)high = mid-1;
            else
            low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0;i<matrix.size();i++)
        {
            bool ans = binary_search(matrix[i],target);
            if(ans)return true;
        }
        return false;
    }
};