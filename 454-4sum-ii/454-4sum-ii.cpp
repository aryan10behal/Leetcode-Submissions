class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> a,b;
        int ans = 0;
        for(int x: nums1)
        {
            for(int y: nums2)
                a[x+y]++;
        }
        for(int x: nums3)
        {
            for(int y: nums4)
                b[x+y]++;
        }
        for(auto w: a)
        {
           ans += b[-1*w.first]*w.second;
        }
        return ans;
    }
};