class Solution {
public:
    static bool bb(const pair<string,int> &a, const pair<string,int> &b)
    {
        if(b.second<a.second)
            return true;
        else if(a.second==b.second)
        {
            if(a.first.compare(b.first)<0)
                return true;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> x;
        int v = 0;
        for(auto s: words)
             m[s]++;
        vector<pair<string, int>> c;
        for(auto it: m)
            c.push_back({it.first, it.second});
        sort(c.begin(),c.end(),bb);
        for(int i=0;i<c.size();i++)
        {
            if(k--)
                x.push_back(c[i].first);
            else
                break;
        }
        return x;
    }
};