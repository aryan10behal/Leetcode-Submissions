class Solution {
public:
    bool p(vector<int> &x, int b)
    {
        int i = 0, j = 1;
        int s = x[0], t = -1, sf = 0, tf = -1, len = 1, n = x.size();
        while(j<b-1)
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
            // if(b == 5)
            //     cout<<j<<" "<<s<<" "<<sf<<" "<<t<<" "<<tf<<" "<<len<<endl;
            j++;
        }
        // if(b == 5)
        //      cout<<len<<endl;
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
            // if(b == 5)
            //     cout<<j<<" "<<s<<" "<<sf<<" "<<t<<" "<<tf<<" "<<len<<endl;
            if(len>=b)
                return true;
            j++;
        }
        return false;
    }
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() == 1)
            return 1;
       int l = 2, h = fruits.size(), m, ans = -1;
        while(l<=h)
        {
            m = (l+h)/2;
            if(p(fruits, m))
            {
                ans = m;
                l = m+1;
            }
            else
                h = m-1;
        }
        return ans;
    }
};