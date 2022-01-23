class Solution {
public:
    int hcf(int a, int b)
    {
        if(a == 0)
            return -1e9;
        if(b == 0)
            return 1e9;
        if(a==b)
            return a;
        if(a==1 || b==1)
            return 1;
        if(a>b)
            return hcf(a-b, b);
        return hcf(b-a, a);
    }
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        int num, den;
        if(c[1][0] > c[0][0])
        {
            num = c[1][1] - c[0][1];
            den = c[1][0] - c[0][0];
        }
        else
        {
            num = c[0][1] - c[1][1];
            den = c[0][0] - c[1][0];
        }
        int z = hcf(abs(num), abs(den));
        num/=z;
        den/=z;
         if(z == -1e9)
            {
                num = -1e9;
                den = 0;
            }
            else if(z == 1e9)
            {
                num = 1e9;
                den = 0;
            }
        //cout<<z<<endl;
        for(int i = 2;i<n;i++)
        {
            int x, y;
            if(c[i][0] > c[i-1][0])
            {
                y = c[i][1] - c[i-1][1];
                x = c[i][0] - c[i-1][0];
            }
            else
            {
                y = c[i-1][1] - c[i][1];
                x = c[i-1][0] - c[i][0];
            }
            z = hcf(abs(y),abs(x));
            y/=z;
            x/=z;
            if(z == -1e9)
            {
                y = -1e9;
                x = 0;
            }
            else if(z == 1e9)
            {
                y = 1e9;
                x = 0;
            }
            //cout<<y<<" "<<x<<endl;
            if(y != num || x != den)
                return false;
        }
        return true;
    }
};