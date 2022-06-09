class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int i = 0, j = num.size()-1;
        vector<int> v(2);
        while(i<j)
        {
            if(num[i]+num[j]==target)
            {
                v[0] = i+1, v[1] = j+1;
                return v;
            }
            if(num[i]+num[j]<target)
                i++;
            else
                j--;
        }
        return v;
    }
};