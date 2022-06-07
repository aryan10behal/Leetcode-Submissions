class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> x(m+n);
        int i = 0, j = 0,k = 0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                x[k++] = nums1[i++];
            }
            else
            {
                x[k++] = nums2[j++];
            }
        }
        while(i<m)
        {
           x[k++] = nums1[i++];
        }
        while(j<n)
        {
           x[k++] = nums2[j++];
        }
        nums1 = x;
    }
};