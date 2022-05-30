class Solution {
public:
    int count(unsigned int x)
    {
        int a = 0;
        while(x!=0)
            x>>=1, a++;
        return a;
    }
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 and divisor == -1)
            return 2147483647;
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return -dividend;
        int sign = 1;
        if(dividend > 0 and divisor < 0 or dividend < 0 and divisor > 0)
            sign = -1;
        int val = 0;
        //cout<<m<<" "<<n<<endl;
        unsigned int dividing = abs(dividend);
        unsigned int divider = abs(divisor);
        int m = count(dividing), n = count(divider);
        cout<<m<<" "<<n<<endl;
        for(int i = m-n;i>=0;i--)
        {
            //cout<<(dividend>>i)<<endl;
            if((dividing>>i) >= divider)
            {
                dividing -= (divider<<i);
                val += (1<<i);
                cout<<val<<"$"<<endl;
            }
        }
        return sign*val;
    }
};