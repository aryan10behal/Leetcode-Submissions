class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return (a[0] < b[0]);
    }
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int> > y_s(101);
        for(auto &r : rectangles) {
            y_s[r[1]].push_back(r[0]);
        }
        for(auto &v : y_s) sort(v.begin(), v.end());
        vector<int> fans(points.size());
        int f = -1;
        for(vector<int> &p: points)
        {
            int y = p[1], x = p[0];
            int sum = 0;
            for(int k = y; k <= 100; k++) {
                sum += y_s[k].end() - lower_bound(y_s[k].begin(), y_s[k].end(), x);
            }
            fans[++f] = sum;
        }
        return fans;
    }
};