class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if(a[0] < b[0])
            return true;
        if(a[0] == b[0])
            return a[1] < b[1];
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), comp);
        int n = p.size()-1;
        int ans = 0, i = p.size() - 1, b = 0, a = p[i][0];
        while(i>=0 and a == p[i][0])
        {
            b = max(b, p[i][1]);
            i--;
        }
        while(i>=0)
        {
            int k = p[i][0], l = 0;
            while(i>=0 and k == p[i][0])
            {
                if(b > p[i][1])ans++;
                l = max(l, p[i][1]);
                i--;
            }
            b = max(l, b);
        }
        return ans;
    }
};