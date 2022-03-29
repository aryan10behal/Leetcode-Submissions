class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        int i = 0;
        for(string x: nums)
        {
            int num = 0;
            for(char y: x)
                num = num*2 + (y-'0');
            v[i++] = num;
        }
        sort(v.begin(), v.end());
        int val = n, k = 0;
        for(i = 0;i<(1<<n), k<n;i++)
        {
            if(i==v[k])
                k++;
            else
            {
                val = i;
                break;
            }
        }
        string ans = "";
        while(val)
        {
            ans += (val%2 + '0');
            val/=2;
        }
        while(ans.size()<n)
            ans+='0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};