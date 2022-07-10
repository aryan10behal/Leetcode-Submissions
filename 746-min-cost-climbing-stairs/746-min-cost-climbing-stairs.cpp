class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==1)
            return 0;
        if(n==2)
           return min(cost[0],cost[1]);
       vector<int> money(n+1);
        money[0] = 0;
        money[1] = 0;
       for(int i=2;i<=n;i++)
       {
            money[i] = min(money[i-1]+cost[i-1],money[i-2]+cost[i-2]);
       }
        return money[n];
    }
};