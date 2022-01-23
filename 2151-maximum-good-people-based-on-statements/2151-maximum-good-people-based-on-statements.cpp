class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for(int i = 0; i< pow(2,n);i++)
        {
            int good = 0;
            queue<int> q;
            int z = i;
            int j = 0;
            vector<int> gd(n, 0);
            while(z!=0)
            {
                if(z&1 == 1)
                {
                    q.push(j);
                    gd[j] = 1;
                }
                z>>=1;
                j++;
            }
            good = q.size();
            while(q.size())
            {
                int k = q.front();
                q.pop();
                j = 0;
                int contra = 0;
                for(int x: statements[k])
                {
                    if((x == 1 && gd[j]!=1) || (x == 0 && gd[j]==1))
                    {
                        contra = 1;
                        break;
                    }   
                    j++;
                }
                if(contra)
                {
                    good = -1e9;
                    break;
                }
            }
            ans = max(good, ans);
        }
        return ans;
    }
};