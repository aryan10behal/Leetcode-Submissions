class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<long long, long long> m;
        for(int x: nums)
        {
            m[x]++;
        }
        long long ans = 0;
        if(k == 0)
        {
            for(auto it: m)
            {
                ans += it.second>=2?1:0;
            }
            return ans;
        }
        for(auto it: m)
        {
            if(m.find(it.first - k) != m.end())
            {
                ans += 1;
            }
        }
        return ans;
    }
};