class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int i = 0, z = 0, ans = 0;
        while(i<fb.size() && fb[i]==0)
        {
            z++;
            i++;
        }
        if(z == fb.size())
            return (z+1)/2 >= n?true:false;
        ans+= z/2;
        z = 0;
        int j = fb.size()-1;
        while(j>i && fb[j]==0)
        {
            z++;
            j--;
        }
        ans+= z/2;
        z = 0;
       // cout<<i<<" "<<j<<endl;
        while(i<j)
        {
            if(fb[i] == 1)
            {
               // cout<<z<<endl;
                ans+= max(0, (z-1)/2);
                z = 0;
            }
            else
            {
                z++;
            }
            i++;
        }
        ans+= max(0, (z-1)/2);
        return ans>=n?true:false;
        // 0000000
    }
};