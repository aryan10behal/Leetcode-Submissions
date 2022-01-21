class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x=0, v, ind, p = -1, n = gas.size();
        for(int i=0;i<n;i++)
        {
            if(x+gas[i]-cost[i] >= 0)
            {
                x += (gas[i]-cost[i]);
                if(p == -1)
                {
                    p = i;
                }
            }
            else
            {
                x = 0;
                p = -1;
            }
        }
        if(p == -1)
            return -1;
        int i = p, k = 0;
        x = 0;
        while(k<n)
        {
            x+=gas[i]-cost[i];
            if(x<0)
                return -1;
            i++;
            i = i%n;
            k++;
        }
        return p;
    }
};