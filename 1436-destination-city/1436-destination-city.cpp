class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> m, n;
        for(vector<string> x: paths)
        {
            m[x[0]]++;
            n[x[0]] = 1;
            n[x[1]] = 1;
        }
        for(auto it: n)
        {
            if(m.find(it.first) == m.end())
                return it.first;
        }
        return "";
    }
};