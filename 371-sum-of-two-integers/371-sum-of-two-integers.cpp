class Solution {
public:
    int getSum(int a, int b) {
        long long c = 0, carry;
        for(int i = 0;i<32;i++)
        {
            int val = (((a>>i)&1) + ((b>>i)&1)) + carry;
            int dig = val&1;
            carry = ((val&2)?1:0);
            c += (dig<<i);
        }
        c += (carry<<32);
        return c;
    }
};