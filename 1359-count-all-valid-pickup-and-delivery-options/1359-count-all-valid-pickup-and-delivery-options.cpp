class Solution {
public:
    long long gcd(long long a, long long b)
    {
        if(a == 0 or b == 0)
            return a==0?b:a;
        if(b%a == 0)
            return a;
        return gcd(b%a, b);
    }
    int countOrders(int n) {
        long long mod = 1e9 + 7;
        n = n*2;
        long long num = 1, den = 1;
        for(int i=1;i<=n;i++)
        {
            num = num*i;
            if((i & 1) == 0)
                den=den*2;
            if(num > mod or den > mod)
            {
                long long x = gcd(min(num, den), max(num,den));
                //cout<<num<<" "<<den<<" "<<x<<endl;
                num/=x;
                num = num%mod;
                den/=x;
            }
        }
        // cout<<num<<" "<<den<<endl;
        return (num/den)%mod;
    }
};