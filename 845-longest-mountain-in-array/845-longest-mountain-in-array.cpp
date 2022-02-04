class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0, ans = 0, x = 1;
        while(j<n)
        {
            if(j<n-1 && arr[j]<arr[j+1])
            {
               while(j<n-1 && arr[j] < arr[j+1])
               {
                    x++;
                    j++;
               }
                int y = x;
               while(j<n-1 && arr[j] > arr[j+1])
               {
                   x++;
                   j++;
               }
                if(y == x)
                    x = 0;
            }
            else
                 j++;
           ans = max(ans, x);
           x = 1;
        }
        return ans == 1?0:ans;
    }
};