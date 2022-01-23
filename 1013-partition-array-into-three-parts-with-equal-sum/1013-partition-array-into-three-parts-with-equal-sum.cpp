class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i =0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%3)
            return false;
        sum/=3;
        int num = 0;
        int count = 0;
        int i = 0;
        while(i<n)
        {
            num+=arr[i];
            if(num == sum)
            {
                num = 0;
                count++;
            }
            i++;
        }
        return count>=3?true:false;
    }
};