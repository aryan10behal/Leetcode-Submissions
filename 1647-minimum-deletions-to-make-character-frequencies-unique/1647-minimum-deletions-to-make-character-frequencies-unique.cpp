class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(char x: s)
            v[x-'a']++;
        sort(v.begin(), v.end(), greater<int>());
        int mx = v[0]-1, ans = 0;
        for(int i = 1;i<v.size();i++)
        {
            if(v[i]==0)
                break;
            if(mx < v[i])
                ans += v[i]-mx;
            mx = max(0,min(v[i], mx)-1);
        }
        return ans;
    }
};