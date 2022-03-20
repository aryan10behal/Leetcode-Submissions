class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> arr(6, 0), arr2(6, 0), arr3(6, 0);
        for(int i=0;i<n;i++)
        {
            arr[tops[i]-1]++;
            arr2[bottoms[i]-1]++;
            if(tops[i] == bottoms[i])
                arr3[tops[i]-1]++;
        }
        int ans = 1e9;
        for(int i = 0;i<6;i++)
        {
            if(arr[i]+arr2[i] - arr3[i] >= n)
                ans = min(ans, min(n-arr[i], n-arr2[i]));
        }
        return ans == 1e9? -1: ans;
    }
};