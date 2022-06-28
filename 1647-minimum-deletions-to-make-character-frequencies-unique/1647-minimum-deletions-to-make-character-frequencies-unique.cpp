class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char x: s)
            mp[x]++;
        vector<int> v;
        for(auto x: mp)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            v.push_back(x.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        int mx = v[0]-1, ans = 0;
        for(int i = 1;i<v.size();i++)
        {
            if(mx < v[i])
                ans += v[i]-mx;
            // cout<<v[i]<<" ";
            mx = max(0,min(v[i], mx)-1);
            // cout<<mx<<" "<<ans<<endl;
        }
        return ans;
    }
};