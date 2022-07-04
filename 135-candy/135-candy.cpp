class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1)
            return 1;
        queue<int> q;
        vector<int> candies(n, 0);
        if(ratings[0] == ratings[1])
            candies[0] = 1;
        else if(ratings[0] < ratings[1])
        {
            candies[0] = 1;
            q.push(0);
        }
        if(ratings[n-1] == ratings[n-2])
            candies[n-1] = 1;
        else if(ratings[n-1] < ratings[n-2])
        {
            candies[n-1] = 1;
            q.push(n-1);
        }
        vector<int> vis(n, 1);
        for(int i = 1;i<n-1;i++)
        {
            if(ratings[i] <= ratings[i-1] and ratings[i] <= ratings[i+1])
            {
                vis[i] = 0;
                candies[i] = 1;
                q.push(i);
            }
        }
        while(q.size())
        {
            int x = q.front();
            q.pop();
            int j = x-1, c = 2;
            while(j>=0)
            {
                if(ratings[j] > ratings[j+1])
                {
                    if(candies[j] > c)
                        break;
                    candies[j] = c++;
                }
                else
                    break;
                j--;
            }
            j = x+1, c = 2;
            while(j<n)
            {
                if(ratings[j] > ratings[j-1])
                {
                    if(candies[j] > c)
                        break;
                    candies[j] = c++;
                }
                else
                    break;
                j++;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            cout<<candies[i]<<" ";
            ans += candies[i];
        }
        return ans;
    }
};