class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        // sort(points.begin(), points.end());
        for(int i=0;i<n;i++)
        {
            for(int j = i+1; j<n;j++)
            {
                int num = points[j][1] - points[i][1], den = points[j][0] - points[i][0];
                if(points[i][0] > points[j][0])
                    num*=-1, den*=-1;
    
                int x = 2;
                //cout<<num<<" "<<den<<endl;
                for(int k=j+1;k<n;k++)
                {
                    int num2 = points[k][1] - points[j][1], den2 = points[k][0] - points[j][0]; 
                    if(points[j][0] > points[k][0])
                        num2*=-1, den2*=-1;
                   // cout<<num2<<":"<<den2<<" ";
                    if(num2*den == num*den2)
                        x++;
                }
                //cout<<endl;
                ans = max(ans, x);
            }
        }
        return ans;
    }
};