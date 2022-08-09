class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), mod = 1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        unordered_map<int, long long> ways;
        long long ans = 0;
        for(int x: arr)
        {
            m[x] = 1;
            ways[x] = 1;
        }
        for(int i = 0;i<n;i++)
        {
            //cout<<arr[i]<<endl;
            for(int j = 0;j<i;j++)
            {
                if(arr[i]%arr[j] == 0 and m.find(arr[i]/arr[j]) != m.end())
                {
                   //cout<<"-->"<<arr[j]<<" ";
                    ways[arr[i]] += ((ways[arr[j]]*ways[arr[i]/arr[j]])%mod);
                    ways[arr[i]]%=mod;
                }
            }
           // cout<<" #"<<ways[arr[i]]<<endl;
            ans = (ans + ways[arr[i]])%mod;
        }
        return ans%mod;
    }
};