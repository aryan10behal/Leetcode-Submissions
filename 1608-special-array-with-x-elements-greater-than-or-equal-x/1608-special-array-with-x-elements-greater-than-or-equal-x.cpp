class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> val(1001, 0);
        for(int x: nums)
        {
            val[x]++;
        }
        int c = 0, b = 0;
        for(int i= 1000;i>=0;i--)
        {
            val[i] += c;
            c = val[i];
            if(i == val[i])
                return i;
        }
        return -1;
    }
};