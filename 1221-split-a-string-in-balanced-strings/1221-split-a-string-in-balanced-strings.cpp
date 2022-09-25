class Solution {
public:
    int balancedStringSplit(string s) {
        int val = 0, ans = 0;
        int i = 0, n = s.size();
        while(i<n)
        {
            val += (s[i++]=='R'?1:-1);
            ans += (val == 0?1:0);
        }
        return ans;
    }
};