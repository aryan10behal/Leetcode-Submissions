class Solution {
public:
    struct comp{
        bool operator()(vector<int> const& p1, vector<int> const& p2)
        {
            return p1[0] < p2[0];
        }
    };
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        map<int, vector<int>> m;
        int n = values.size();
        for(int i = 0;i<n;i++)
            m[labels[i]].push_back(values[i]);
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for(auto &it: m)
        {
            sort(it.second.begin(), it.second.end());
            int m = it.second.size() - 1;
            vector<int> x = {it.second[m], it.first, m, useLimit};
            pq.push(x);
        }
        vector<int> ans;
        while(pq.size())
        {
            vector<int> y = pq.top();
            pq.pop();
            ans.push_back(y[0]);
            if(ans.size() == numWanted)
                break;
            if(y[3]-1 > 0 and y[2]-1>=0)
                pq.push({m[y[1]][y[2]-1], y[1], y[2]-1, y[3]-1});
        }
        int val = 0;
        for(int x: ans)
            val += x;
        return val;
    }
};