class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> left(n, 0);
        int z = 0, o = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '1')
            {
                left[i] = z;
                o++;
            }
            else
            {
                left[i] = o;
                z++;
            }
        }
        z = 0, o = 0;
        long long ans = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(s[i] == '1')
            {
                ans = ans + z*left[i];
                o++;
            }
            else
            {
                ans = ans + o*left[i];
                z++;
            }
        }
        return ans;
    }
};