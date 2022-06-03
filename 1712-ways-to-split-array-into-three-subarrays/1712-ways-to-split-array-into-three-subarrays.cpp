class Solution {
public:
    int bin(vector<int> &prefix, int b, int e)
    {
        int l = b, h = e, m, ans1 = -1;
        while(l<=h)
        {
            m = (l+h)/2;
            int a = prefix[m]-prefix[b-1] - prefix[b-1];
            int c = prefix[e+1] - prefix[m] - (prefix[m]-prefix[b-1]);
            if(a>=0)
            {
                h=m-1;
                if(c>=0)
                    ans1 = m;
            }
            else
                l = m+1;
        }
       if(ans1 == -1)
            return 0;
        int ans2 = ans1;
        l = b, h = e;
        while(l<=h)
        {
            m = (l+h)/2;
            int a = prefix[m]-prefix[b-1] - prefix[b-1];
            int c = prefix[e+1] - prefix[m] - (prefix[m]-prefix[b-1]);
            if(c>=0)
            {
                l = m+1;
                if(a>=0)
                    ans2 = m;
            }
            else
                h = m-1;
        }
        return ans2 - ans1 + 1;
    }
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        long long ans = 0;
        int mod = 1e9+7;
        for(int i=1;i<=n-2;i++)
        {
           ans += bin(prefix, i, n-2);
           ans%=mod;
        }
        return ans%mod;
    }
};