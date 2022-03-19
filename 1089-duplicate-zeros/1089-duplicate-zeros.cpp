class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int z = 0;
        for(int x: arr)
            if(x == 0)
                z++;
        int n = arr.size();
        for(int i = n-1;i>=0;i--)
        {
            if(arr[i] == 0)
                z--;
            if(i+z < n)
            {
                arr[i+z] = arr[i];
                if(arr[i] == 0)
                {
                    if(i+z+1 < n)
                        arr[i+z+1] = 0;
                }
            }
        };
    }
};