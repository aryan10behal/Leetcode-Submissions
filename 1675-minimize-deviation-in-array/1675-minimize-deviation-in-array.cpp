class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mindiff,mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                nums[i]*=2;
            }
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        mindiff=mx-mn;
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++)
        {
            q.push(nums[i]);
        }
        while(q.top()%2==0)
        {
            int temp=q.top();
            q.pop();
            mindiff=min(mindiff,temp-mn);
            temp/=2;
            mn=min(mn,temp);
            q.push(temp);
        }
        mindiff=min(mindiff,q.top()-mn);
        return mindiff;
        
    }
};