class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int m) {
        int mask = 0;
        int n = cells.size();
        for(int i = 0;i<n;i++)
        {
            mask += (cells[i]<<(n-i-1));
        }
        //cout<<mask<<endl;
        unordered_map<int, int> mp;
        mp[mask] = 0;
        int turns = 0, f = 0;
        while(true)
        {
            int val = 0;
            for(int i = 1;i<n-1;i++)
                val += ((!(((mask>>(i-1))&1) ^ ((mask>>(i+1))&1)))<<i);
            mask = val;
            //cout<<mask<<endl;
            turns++;
            if(mp.find(mask) != mp.end())
            {
                f = mp[mask];
                break;
            }
            mp[mask] = turns;
        }
        m-=mp[mask];
        m%=(turns - mp[mask]);
        while(m>0)
        {
            int val = 0;
            for(int i = 1;i<n-1;i++)
                val += ((!(((mask>>(i-1))&1) ^ ((mask>>(i+1))&1)))<<i);
            mask = val;
            m--;
        }
        for(int i = 0;i<n;i++)
        {
            cells[n-i-1] = ((mask>>i)&1);
        }
        return cells;
    }
};