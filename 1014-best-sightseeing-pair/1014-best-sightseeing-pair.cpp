class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int f = values[0];
        int ans = 0;
        for(int i = 1;i<n;i++)
        {
            f--;
            ans = max(ans, f + values[i]);
            if(f < values[i])
                f = values[i];
        }
        return ans;
    }
};