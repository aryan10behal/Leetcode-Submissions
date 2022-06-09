class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int arr[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        sort(rs.begin(), rs.end());
        int m = rs.size();
        
        
        int mask = arr[0] + arr[1] + arr[2] + arr[3];
        int count = 0;
        
        int c = 0;
        for(int i = 0;i<m;i++)
        {
            int row = rs[i][0];
            c++;
            int x = 0;
            while(i<m and rs[i][0] == row)
                x += arr[rs[i++][1] - 1];
            //cout<<x<<endl;
            i--;
            int k = 1;
            for(int j = 0; j<=6;j++)
            {   
                if(j==k)
                {
                    //cout<<((mask<<i)^x)<<" "<<((mask<<i)|x)<<endl;
                    if(((mask<<j)^x) == ((mask<<j)|x)) 
                    {
                        count++;
                        k+=2;
                    }
                    k+=2;
                }
            }
        }
        return count + (n-c)*2;
    }
};