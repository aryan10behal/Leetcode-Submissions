// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};
    bool p(int a, int b, int x, int y)
    {
         return (a>=0 && b>=0 && a<x && b<y);
        
    }
    pair<int,int> endPoints(vector<vector<int>> matrix){
       int x = 0, y = 0, prev_x = 0, prev_y = 0;
       int m = matrix.size(), n = matrix[0].size();
       int dir = 0;
       while(p(x, y, m, n))
       {
            if(matrix[x][y] == 1)
            {
                dir = (dir+1)%4;
                matrix[x][y] = 0;
            }
            //cout<<x<<" "<<y<<endl;
            prev_x = x;
            prev_y = y;
            x += dir_x[dir];
            y += dir_y[dir];
       }
       return {prev_x, prev_y};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends