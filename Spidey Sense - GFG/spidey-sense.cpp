// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    int dir_x[4] = {1,0,-1,0};
    int dir_y[4] = {0,1,0,-1};
    bool ps(int a, int b, int x, int y)
    {
        if(a>=0 && a<x && b>=0 && b<y)
            return true;
        return false;
    }
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int>> ans(M, vector<int>(N, 0));
        queue<pair<pair<int, int>,int>> q;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j] == 'W')
                    {
                        ans[i][j] = -1;
                        matrix[i][j] = '-';
                    }
                if(matrix[i][j] == 'B')
                    {
                        ans[i][j] = 0;
                        matrix[i][j] = '-';
                        q.push({{i, j}, 0});
                    }
            }
        }
        while(q.size())
        {
            pair<pair<int, int>,int> p = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int x = p.first.first + dir_x[i];
                int y = p.first.second + dir_y[i];
                if(ps(x, y, M, N) && matrix[x][y] !='-')
                {
                    matrix[x][y] = '-';
                    ans[x][y] = p.second+1; 
                    q.push({{x,y},p.second + 1});
                }
            }
        }
        for(int i=0;i<M;i++)
        {
            
            for(int j=0;j<N;j++)
            {
               if(matrix[i][j] != '-')
                    ans[i][j] = -1;
            }
        }
        return ans;
        // Your code goes here
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends