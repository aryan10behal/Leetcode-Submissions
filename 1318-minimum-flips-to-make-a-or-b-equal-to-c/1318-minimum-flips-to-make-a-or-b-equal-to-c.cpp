class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 31;i>=0;i--)
        {
            int x = (a>>i)&1;
            int y = (b>>i)&1;
            int z = (c>>i)&1;
            if(z == 1 and x == 0 and y == 0)
                ans++;
            if(z == 0)
            {
                if(x == 1)
                    ans++;
                if(y == 1)
                    ans++;
            }
        }
        return ans;
    }
};