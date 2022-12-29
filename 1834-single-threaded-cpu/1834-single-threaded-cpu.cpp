class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& t) {
        priority_queue<vector<long long>> pq, wait;
        int n = t.size();
        // cout<<n<<endl;
        for(int i=0;i<n;i++)
            pq.push({-t[i][0], -t[i][1], -i});
        int cur = 0;
        vector<int> ans;
        // while(pq.size())
        // {
        //     cout<<pq.top()[0]<<" "<<pq.top()[1]<<" "<<pq.top()[2]<<endl;
        //     pq.pop();
        // }
        while(pq.size() != 0 or wait.size() != 0)
        {
            if(pq.size())
            {
                if(abs(pq.top()[0]) > cur and wait.size() == 0)
                {
                    wait.push({pq.top()[1], pq.top()[2], pq.top()[0]});
                    pq.pop();
                }
                else
                {
                    while(pq.size() and -pq.top()[0] <= cur)
                    {
                        wait.push({pq.top()[1], pq.top()[2], pq.top()[0]});
                        pq.pop();
                    }
                }
            }
            if(wait.size())
            {
                ans.push_back(-wait.top()[1]);
                // cout<<-wait.top()[2]<<" "<<-wait.top()[0]<<" "<<-wait.top()[1]<<endl;
                if(-wait.top()[2] > cur)
                    cur = -(wait.top()[2] + wait.top()[0]);
                else
                    cur += -wait.top()[0];
                // cout<<cur<<endl;
                wait.pop();
            }
        }
        return ans;
    }
};