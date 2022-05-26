class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n!=0)
        {
            ans += (n%2 == 1? 1:0);
            n>>=1;
        }
        return ans;
    }
};