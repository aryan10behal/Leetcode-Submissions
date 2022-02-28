class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        nums.push_back(nums[nums.size()-1] - 1);
        n++;
        string x = "";
        x = to_string(nums[0]);
        for(int i = 1;i<n;i++)
        {
            if(nums[i-1] != nums[i]-1)
            {
                string a = to_string(nums[i-1]);
                if(a!=x)
                {
                    x.append("->");
                    x.append(a);
                }
                ans.push_back(x);
                x = to_string(nums[i]);
            }
        }
        return ans;
    }
};