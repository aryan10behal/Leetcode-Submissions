class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x: nums)
            pq.push(x);
        long long c = 0;
        long long sum = 0;
        while(pq.size() && k)
        {
            long long x = pq.top();
            pq.pop();
            if(c < x)
            {
                //cout<<x<<" "<<c<<endl;
                int n = (x - c) - 1;
                //cout<<n<<" "<<k<<endl;
                if(n >= k)
                {
                    sum += ((c+k)*(c+k+1))/2 - (c*(c+1))/2;
                    k = 0;
                }
                else
                {
                    sum += ((c+n)*(c+n+1))/2 - (c*(c+1))/2;
                    k-=n;
                }
                c = x;
            }
            //cout<<sum<<endl;
            if(k==0)
                break;
        }
        if(k)
        {
            sum += ((c+k)*(c+k+1))/2 - (c*(c+1))/2;
        }
        return sum;
    }
};