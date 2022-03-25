class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return (a[0]-a[1] < b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);
        int ans = 0;
        int i = 0, n = costs.size()/2;
        for(vector<int> x: costs)
        {
            //cout<<x[0]<<" "<<x[1]<<endl;
            if(i<n)
                ans += x[0];
            else
                ans += x[1];
            i++;
        }
        return ans;
    }
};