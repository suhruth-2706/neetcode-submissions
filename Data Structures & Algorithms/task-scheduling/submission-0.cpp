class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char, int> mp;

        for (char task : tasks) 
        {
            mp[task]++;
        }

        for (auto it : mp) 
        {
            pq.push(it.second);
        }

        int ans = 0;

        while (!pq.empty()) 
        {
            vector<int> remain;
            int cycle = n + 1;

            while (cycle && !pq.empty()) {
                int freq = pq.top();
                pq.pop();

                if (freq > 1) {
                    remain.push_back(freq - 1);
                }

                ans++;
                cycle--;
            }

            for (int cnt : remain) {
                pq.push(cnt);
            }

            if (pq.empty()) break;

            ans += cycle;
        }

        return ans;
    }
};