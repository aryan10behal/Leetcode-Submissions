class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int ans = 0, n = grades.size();
        int l = 0, h = n;
        while(l<=h)
        {
            long long m = (l+h)/2;
            if((m*(m+1))/2 <= n)
            {
                ans = m;
                l = m+1;
            }
            else
                h = m-1;
        }
        return ans;
    }
};