class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int x: piles)
            pq.push(x);
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            x = x/2 + ((x&1 == 1)?1:0);
            pq.push(x);
        }
        int x = 0;
        while(pq.size())
        {
            x+= pq.top();
            pq.pop();
        }
        return x;
    }
};