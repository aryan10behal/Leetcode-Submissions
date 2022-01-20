class Solution {
public:
    bool p(vector<int>& piles, long long h, long long mid)
    {
        int c = 0;
        for(int i: piles)
        {
            c += (i/mid);
            if(i%mid)
                c++;
        }
        if(c<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, hi = 1e14, ans;
        while(l<=hi)
        {
            long long mid = (l+hi)/2;
            if(p(piles, h, mid))
            {
                ans = mid;
                hi = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};