class Solution {
public:
    struct myComp {
        constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b)
        {
            return a.first < b.first;
        }
    };
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,myComp> pq;
        pq.push({nums[0], 0});
        dp[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            int mx = -1e9;
            while(pq.size())
            {
                pair<int, int> x = pq.top();
                if(x.second >= i - k)
                {
                    mx = max(mx, x.first);
                    break;
                }
                else
                {
                    pq.pop();
                }
            }
            dp[i] = nums[i] + mx;
            pq.push({dp[i], i});
        }
        return dp[n-1];
    }
};