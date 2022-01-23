class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for(int i = 0; i< pow(2,n);i++)
        {
            int good = 0;
            queue<int> q;
            int bitmask = i;
            int j = 0;
            vector<int> gd(n, 0);
            while(bitmask!=0)
            {
                if(bitmask&1 == 1)
                {
                    q.push(j);
                    gd[j] = 1;
                }
                bitmask>>=1;
                j++;
            }
            
            // count the number of 1s in our bitmask or people who we assumed to be good...
            good = q.size();
            
            
            // bfs on assumed 'good' people to check if their statements contradict!!
            while(q.size())
            {
                int k = q.front();
                q.pop();
                j = 0;
                int contradiction = 0;
                for(int x: statements[k])
                {
                    // checking for contradiction....
                    // if a good person says someone is good but he is not assumed to good
                    // or
                    // if he is called bad but we assumed him to be good...
                    if((x == 1 && gd[j]!=1) || (x == 0 && gd[j]==1))
                    {
                        contradiction = 1;
                        break;
                    }   
                    j++;
                }
                // if contradiction, we will avoid this result... so assigning -INF to good
                if(contradiction)
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