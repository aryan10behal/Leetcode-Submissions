class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int> &b)
    {
        if(a[0] < b[0])
            return true;
        else if(a[0] == b[0])
        {
            if(a[1] > b[1])
                return true;
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        // for(int i=0;i<intervals.size();i++)
        // {
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        // }
        int s = intervals[0][0], e = intervals[0][1];
        int ans = 1;
        for(int i = 0;i<intervals.size();i++)
        {
            if(intervals[i][1] > e)
            {
                ans++;
                e = intervals[i][1];
                s = intervals[i][0];
            }
        }
        return ans;
    }
};