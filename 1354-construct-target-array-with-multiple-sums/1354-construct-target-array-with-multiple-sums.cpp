class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long s = 0, n = target.size();
        if(n == 1)
            return target[0] == 1? true:false;
        priority_queue<long long> pq;
        for(int i = 0;i<n;i++)
        {
            pq.push((long long)target[i]);
            s += target[i];
        }
        while(pq.top()!=1)
        {
            long long x = pq.top();
            pq.pop();
            long long contri = s - x;
            long long val = x - contri;
            if(val <= 0)
                return false;
            if(val > pq.top())
                val = val - ((val/contri)-1)*contri;
            cout<<val<<endl;
            s -= (x - val);
            x = val;
            pq.push(x);
        }
        while(pq.size())
        {
            int x = pq.top();
            pq.pop();
            if(x!=1)
                return false;
        }
        return true;
    }
};