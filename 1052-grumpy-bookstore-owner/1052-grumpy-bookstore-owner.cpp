class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int min) {
        int n = c.size();
        
        int m = -1, s = 0, z = 0;
        int i = 0, j = 0, st = -1, en = -1;
        while(i<min-1)
        {
            if(g[i] == 1)
                z++;
            s+=c[i];
            i++;
        }
        while(i<n)
        {
            if(g[i] == 1)
            { 
                z++;
                s+=c[i];
            }
            if(z>0)
            {
                if(s > m)
                    st = j, en = i, m = s;
            }
            if(g[j] == 1)
            {
                z--;
                s-=c[j];
            }
            i++, j++;
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(g[i] == 0)
                ans+=c[i];
            else
            {
                if(i>=st && i<=en)
                    ans+=c[i];
            }
        }
        return ans;
    }
};