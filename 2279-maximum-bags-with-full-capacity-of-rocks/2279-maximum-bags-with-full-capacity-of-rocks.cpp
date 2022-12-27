class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.first - a.second) < (b.first - b.second);
    }
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        int n = c.size();
        vector<pair<int, int>> x;
        for(int i=0;i<n;i++)
            x.push_back({c[i],r[i]});
        sort(x.begin(), x.end(), comp);
        int cc = 0;
        for(int i=0;i<n;i++)
        {
            if(ar + x[i].second >= x[i].first)
            {
                cc++;
                ar -= (x[i].first - x[i].second);
            }
        }
        return cc;
    }
};