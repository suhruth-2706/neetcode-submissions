class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nsm(n,0),psm(n,0);
        for(int i = 0;i<n;i++)
        {
            int curr = i-1;
            while(curr != -1 && heights[curr] >= heights[i])
                curr = psm[curr];
            psm[i] = curr;
        }
        for(int i = n-1;i>=0;i--)
        {
            int curr = i+1;
            while(curr != n && heights[curr] >= heights[i])
                curr = nsm[curr];
            nsm[i] = curr;
        }
        int area = 0;
        for(int i = 0;i<n;i++)
        {
            area = max(area,(nsm[i] - psm[i] - 1)*heights[i]);
        }
        return area;
    }
};