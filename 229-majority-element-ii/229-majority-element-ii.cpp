class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = -1, n2 = -1, c = 0, c1 = 0;
        for(int x: nums)
        {
            if(x == n1)
                c++;
            else if(x == n2)
                c1++;
            else if(c == 0)
            {
                c +=1;
                n1 = x;
            }
            else if(c1 == 0)
            {
                c1 += 1;
                n2 = x;
            }
            else
            {
                c1--;
                c--;
            }
        }
        c1 = 0, c = 0;
        for(int x:nums)
        {
            if(n1 ==  x)
                c++;
            else if(n2 == x)
                c1++;
        }
        int n = nums.size();
        vector<int> ans;
        if(c>n/3)
            ans.push_back(n1);
        if(c1>n/3)
            ans.push_back(n2);
        return ans;
        
    }
};