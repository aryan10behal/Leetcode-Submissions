class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int sum_now = arr[0], final_sum = arr[0];
        int n = arr.size();
        if(n==1)
            return arr[0];
        vector<int> left(n), right(n);
        for(int i=1;i<arr.size();i++)
        {
            left[i] = sum_now;
            if(sum_now >= 0 and arr[i] > 0)
                sum_now+= arr[i];
            else if(sum_now >= 0 and arr[i] < 0)
            {
                if(arr[i] + sum_now > 0)
                    sum_now += arr[i];
                else
                    sum_now = arr[i];
            }
            else if(sum_now < 0)
                sum_now = arr[i];
            final_sum = max(final_sum, sum_now);
        }
        int ans = final_sum;
        sum_now = arr[n-1], final_sum = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i] = sum_now;
            if(sum_now >= 0 and arr[i] > 0)
                sum_now+= arr[i];
            else if(sum_now >= 0 and arr[i] < 0)
            {
                if(arr[i] + sum_now > 0)
                    sum_now += arr[i];
                else
                    sum_now = arr[i];
            }
            else if(sum_now < 0)
                sum_now = arr[i];
        }
        ans = max(ans, final_sum);
        left[0] = 0, right[n-1] = 0;
        for(int i = 0;i<n;i++)
        {
           // cout<<left[i]<<" "<<right[i]<<endl;
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};