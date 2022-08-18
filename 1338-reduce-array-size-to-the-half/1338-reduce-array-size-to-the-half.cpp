class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x: arr)
            mp[x]++;
        int n = arr.size();
        vector<pair<int, int>> v;
        for(auto x: mp)
            v.push_back({x.first, x.second});
        sort(v.begin(), v.end(), comp);
        int b = 0, c = 0;
        for(pair<int, int> x: v)
        {
            c += x.second;
            b++;
            if(2*c>=n)
                return b;
        }
        return 0;
    }
};