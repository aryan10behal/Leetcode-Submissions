class Solution {
public:
    string getSmallestString(int n, int k) {
       // 50, 3
       // awz, 
        string ans = "";
        while(n)
        {
            int can_add = min(26, k - (n-1));
            k-=can_add;
            ans += (char)(can_add+'a'-1);
            n--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};  