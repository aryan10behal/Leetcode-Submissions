class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, int> m, forb;
        for(int x: forbidden)
            forb[x] = 1;
        queue<pair<int, pair<int, int>>> q;
        m[0]=1;
        q.push({0, {0,0}});
        while(q.size())
        {
            pair<int, pair<int,int>> p = q.front();
            q.pop();
            if(p.first == x)
                return p.second.first;
            if(p.second.second == 0)
            {
                if(p.first-b >=0 && forb.find(p.first - b) == forb.end() &&  m.find(p.first - b) == m.end())
                {
                    m[p.first - b] = 1;
                    q.push({p.first - b,{p.second.first + 1, 1}});
                }
            }
            if(p.first + a <= x + 6000 and forb.find(p.first + a) == forb.end() and m.find(p.first + a) == m.end())
            {
                m[p.first + a] = 1;
                q.push({p.first + a, {p.second.first + 1, 0}});
            }
        }
        return -1;
    }
};