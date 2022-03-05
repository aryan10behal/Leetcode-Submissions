class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for(int x: nums)
            m[x]++;
        vector<pair<int, int>> v;
        for(auto it: m)
            v.push_back({it.first, it.second});
        int n =v.size();
        if(n==1)
            return v[0].first*v[0].second;
        vector<int> taken(n,0);
        vector<int> not_taken(n, 0);
        taken[0] = v[0].first*v[0].second;
        not_taken[0] = 0;
        if(v[0].first+1 == v[1].first)
            taken[1] = v[1].first*v[1].second;
        else
            taken[1] = taken[0] + v[1].first*v[1].second;
        not_taken[1] = taken[0];
        
        for(int i=2;i<n;i++)
        {
            if(v[i-1].first+1 == v[i].first)
                taken[i] = max(not_taken[i-1], taken[i-2]) + v[i].first*v[i].second;
            else 
                taken[i] =  max(not_taken[i-1], taken[i-1]) + v[i].first*v[i].second;
            not_taken[i] = max(taken[i-1], not_taken[i-1]);
        }
        return max(not_taken[n-1], taken[n-1]);
    }
};