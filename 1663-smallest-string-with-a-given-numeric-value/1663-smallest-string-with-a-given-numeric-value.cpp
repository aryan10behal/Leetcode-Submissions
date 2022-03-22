class Solution {
public:
    string getSmallestString(int n, int k) {
       // 50, 3
       // awz, 
        string ans = "";
        while(n)
        {
            char can_add = min(26, k - ((n--)-1));
            k-=can_add;
            ans += (can_add + 96);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};  