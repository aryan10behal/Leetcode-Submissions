class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if(a[1] < b[1])
            return true;
        else if(a[1] == b[1])
            return a[0] > b[0];
        return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int ans = 1;
        int s = pairs[0][0], e = pairs[0][1];
        for(int i = 1;i<pairs.size();i++)
        {
            if(pairs[i][0] > e)
            {
                e = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};