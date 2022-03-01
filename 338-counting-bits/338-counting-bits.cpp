class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1, 0);
        int x = 1;
        v[0] = 0;
        bool done = false;
        while(true)
        {
            for(long long i = x; i<2ll*x;i++)
            {
                if(i>n)
                {
                    done = true;
                    break;
                }
                v[i] = v[i-x]+1;
            }
            if(done)
                break;
            x<<=1;
        }
        return v;
    }
};