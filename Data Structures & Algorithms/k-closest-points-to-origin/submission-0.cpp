class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            // Compare squared distances to avoid expensive sqrt() calls
            long long dist1 = (long long)a[0] * a[0] + (long long)a[1] * a[1];
            long long dist2 = (long long)b[0] * b[0] + (long long)b[1] * b[1];
            
            // For a Min-Heap (closest elements first), return true if dist1 > dist2
            return dist1 > dist2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>,cmp> pq;

        for(int i = 0;i<points.size();i++)
        {
            pq.push(points[i]);
        } 
        vector<vector<int>>ans;
        while(k--)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        
    }
};
