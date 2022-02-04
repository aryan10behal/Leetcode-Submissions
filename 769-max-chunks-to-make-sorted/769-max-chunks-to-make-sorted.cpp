class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int high = 0, n = arr.size();
        int parts = 0;
        for(int i = 0;i<n;i++)
        {
            if(arr[i] > high)
                high = arr[i];
            else if(arr[i]<=high && high == i)
            {
                parts++;
                high++;
            }
        }
        return parts;
    }
};