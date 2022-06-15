class Solution {
public:
    static bool comp(const string a,const string b)
    {
        return (a.size() < b.size());
    }
    int diff(string &a, string &b)
    {
        if(a.size()-b.size()!=1)
            return 0;
        int v = 0;
        for(int i=0, j=0; i<a.size() && j<b.size();i++,j++)
        {
            if(a[i]!=b[j])
            {
                v++;
                j--;
            }
            if(v>1)
            {
                //cout<<v<<" "<<a<<" "<<b<<" "<<a[i]<<b[j]<<endl;
                return 0;
            }
        }
        return 1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),comp);
        vector<pair<int, string>> dp(n, pair<int, string>());
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            dp[i] = {1, words[i]};
            for(int j=i-1;j>=0;j--)
            {
                if(diff(words[i],dp[j].second)==1)
                {
                    if(dp[i].first<=dp[j].first)
                    {
                        dp[i] = {dp[j].first+1, words[i]};
                    }
                }
            }
            ans = max(ans, dp[i].first);
        }
        return ans;
    }
};