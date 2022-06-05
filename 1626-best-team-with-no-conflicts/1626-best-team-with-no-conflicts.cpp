class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
         vector<vector<int>>data;
        
        int n = scores.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            data.push_back({ages[i],scores[i]});
            
        }
        sort(data.begin(),data.end());
        dp[0] = data[0][1];
        int mm = dp[0];
        
        for(int i=1;i<n;i++){
            dp[i] = data[i][1];
            for(int j=0;j<i;j++){
                if(data[j][1]<=data[i][1]){
                    dp[i] = max(dp[i],dp[j]+data[i][1]);
                }
            }
            mm = max(mm,dp[i]);
        }
        return mm;
    }
};