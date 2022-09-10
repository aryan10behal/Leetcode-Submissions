class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        vector<vector<vector<int>>> ProfitDP(days,vector<vector<int>>(k+1,vector<int>(2)));
        
        //solve special cases
        if(days<=0|| k<=0) return 0;
        if(days<2*k){
            int res = 0;
            for (int i = 1; i < days; i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        
        for (int i = 0; i < days; i++) {
            for (int j = 0; j <= k; j++) {
                ProfitDP[i][j][0] = -1000000000;
                ProfitDP[i][j][1] = -1000000000;
            }
        }
        
        ProfitDP[0][0][0] = 0;
        ProfitDP[0][1][1] = - prices[0];
        

        for(int i = 1;i<days;i++){
            for(int j = 0;j<=k;j++){
                ProfitDP[i][j][0] = max(ProfitDP[i-1][j][0],ProfitDP[i-1][j][1]+prices[i]);
                if(j>0) ProfitDP[i][j][1] = max(ProfitDP[i-1][j][1], ProfitDP[i-1][j-1][0]-prices[i]);
               
            }
        }
        
        int res = 0; 
        for(int j =0;j<=k;j++){
            res = max(res,ProfitDP[days-1][j][0]);
        }
        return res;
    
    }
};