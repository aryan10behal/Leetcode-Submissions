class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        long long ans=0,s=0;
        while(i<j)
        {
            long long k=height[i]<height[j]?height[i]:height[j];
            s = (j-i)*k;
           ans = max(ans, s);
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};