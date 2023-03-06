class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> x(2001);
        for(int k: arr)
        {
            x[k]++;
        }
        for(int i=1;i<=2000;i++)
        {
            if(x[i] == 0)
                k--;
            if(k==0)
                return i;
        }
        return -1;
    }
};