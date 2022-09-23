class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, p = 1;
        int mod = 1e9+7;
        while(n>=1)
        {
            long long j = n;
            while(j!=0)
            {
                ans += (j%2)*p;
                j/=2;
                p = (p*2)%mod;
            }
            ans %= mod;
            n--;
        }
        return ans;
    }
};