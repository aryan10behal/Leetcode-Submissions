class Solution {
public:
    int reverse(int x) {
        int sign = x>=0?1:-1;
        int num = 0;
        int max = 2147483647, min = -2147483648;
        while(x!=0)
        {
            if(max/10 < num || min/10 > num)
            {
                return 0;
            }
            num = num*10 + x%10;
            x/=10;
        }
        return num;
    }
};