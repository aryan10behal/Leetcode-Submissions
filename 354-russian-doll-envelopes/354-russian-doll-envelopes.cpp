class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if(a[0] < b[0])
            return true;
        else if(a[0] == b[0])
        {
            if(a[1] > b[1])
                return true;
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelope) {
        sort(envelope.begin(), envelope.end(), comp);
        vector<int> lis;
        for(int i = 0;i<envelope.size();i++){
            int ele = envelope[i][1];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        return lis.size();
    }
};