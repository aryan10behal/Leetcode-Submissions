class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int score = 0;
        for(int i = n-2;i>=n/3;i-=2)
        {
            score += piles[i];
        }
        return score;
    }
};