class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0,high = 1e9,mid,ans;
        int sum =0,d;
        while(low<high)
        {
           mid = (low+high)/2;
            sum=0;
            d=0;
            for(int i=0;i<weights.size();i++)
            {
                if(weights[i]>mid)
                    d = 1e9;
                if(sum+weights[i]>mid)
                { 
                    d++;
                    sum = 0;
                }
                sum += weights[i];
            }
            d++;
            //cout<<d<<endl;
            if(d<=days)
            {
               ans = mid;
               high = mid;
            }
            else
                low = mid+1;     
        }
        return ans;
    }
};