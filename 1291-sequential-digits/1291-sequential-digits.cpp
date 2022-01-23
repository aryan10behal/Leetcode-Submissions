class Solution {
public:
    long long making(int start, int dig)
    {
        long long int x = 0;
        int j = 0;
        while(j<dig)
        {
            j++;
            x = x*10 + start;
            start++;
        }
        return x;
    }
    void make_num(vector<int> &ans, int &low, int &high, int dig)
    {
        for(int j=1;j<=10-dig;j++)
        {
            long long k = making(j, dig);
            if(k>=low && k<=high)
            {
                ans.push_back((int)k);
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1;i<=10;i++)
        {
            make_num(ans, low, high, i);
        }
        return ans;
    }
};