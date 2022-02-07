class Solution {
public:
    int bin(vector<int>& ages, int l, int h, int a)
    {
        int ans = h+1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if((2*ages[m] <= a + 14))
                l = m+1;
            else
            {
                ans = m;
                h = m-1;
            }
        }
        return ans;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int n = ages.size(), ans = 0;
        int s = 0;
        for(int i = n-1;i>=1;i--)
        {
            if(i<n-1)
            {
                if(ages[i+1] == ages[i] && ages[i]> 14)
                    s++;
                else
                    s = 0;
                ans += s;
            }
            int x = bin(ages, 0, i-1, ages[i]);
            ans += (i-x);
        }
         if(ages[1] == ages[0] && ages[0]> 14)
                    s++;
            else
                s = 0;
            ans += s;
        return ans;
    }
};