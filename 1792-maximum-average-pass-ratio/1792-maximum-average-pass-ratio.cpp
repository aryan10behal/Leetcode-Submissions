class Solution {
public:
    struct comp{
        bool operator()(const pair<double, int>& a, const pair<double, int> &b)
        {
            if(a.first < b.first)
                return true;
            return false;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        int n = classes.size();
        priority_queue<pair<double, int>, vector<pair<double, int>>, comp> pq;
        double ans = 0;
        int i = 0;
        for(vector<int> x: classes)
        {
            double a = x[0], b = x[1];
            pq.push({((a+1)/(b+1) - a/b), i});
            i++;
        }
        while(k>0)
        {
            k--;
            pair<double, int> x = pq.top();
            pq.pop();
            classes[x.second][0]++;
            classes[x.second][1]++;
            double a = classes[x.second][0], b = classes[x.second][1];
            pq.push({((a+1)/(b+1) - a/b), x.second});
        }
        for(vector<int> x: classes)
        {
            double a = x[0], b = x[1];
            ans += a/b;
        }
        ans/=n;
        return ans;
    }
};