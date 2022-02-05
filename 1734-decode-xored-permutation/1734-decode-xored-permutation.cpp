class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x = 0;
        int n = encoded.size()+1;
        for(int i = 1;i<=n;i++)
        {
            x = x^i;
        }
        int y = 0;
        for(int i = 0;i<n-1;i+=2)
        {
            y ^= encoded[i];
        }
        int last = x^y;
        vector<int> ans(n);
        ans[n-1] = last;
        for(int i = n-2;i>=0;i--)
        {
            ans[i] = encoded[i]^last;
            last = ans[i];
        }
        return ans;
    }
};