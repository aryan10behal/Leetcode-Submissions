class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> sum;
        long long ans = 0;
        int mod = 1e9+7;
        for(int i = 0;i<arr.size();i++)
        {
            if(sum.find(target - arr[i]) !=sum.end())
                ans += sum[target - arr[i]];
            ans%=mod;
            for(int j = 0;j<i;j++)
                sum[arr[i] + arr[j]]++;
        }
        return ans%mod;
    }
};