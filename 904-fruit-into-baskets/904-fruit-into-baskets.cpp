class Solution {
public:
    int totalFruit(vector<int>& x) {
        if(x.size() == 1)
            return 1;
        int s = x[0], t = -1, sf = 0, tf = -1, len = 1, n = x.size();
        int mx = 2;
        int j = 1;
      while(j<n)
        {
            if(x[j] == s or x[j] == t)
            {
                if(x[j] == s and j>0 and x[j-1]!=s)
                    sf = j;
                else if(x[j] == t and j>0 and x[j-1]!=t)
                    tf = j;
                len++;
            }
            else
            {
                if(t == -1)
                {
                    tf = j;
                    t = x[j];
                    len++;
                }
                else
                {
                    if(tf > sf)
                    {
                        sf = j;
                        len = j - tf + 1;
                        s = x[j];                        
                    }
                    else
                    {
                        tf = j;
                        len = j-sf+1;
                        t = x[j];
                    }
                }
            }
          mx = max(len, mx);
            j++;
        }
        return mx;
    }
};