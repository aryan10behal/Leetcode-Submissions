class Solution {
public:
    const int dx[4] = {-1,0,1,0} ;
    const int dy[4] = {0,1,0,-1} ;
    bool solve(vector<vector<int>>& grid,int r,int c ){
        queue<pair<int,int>> q ;
        for(int i = 0 ; i < c ; i ++ ) 
        {
            if(grid[0][i] == 0)
                q.push({0,i}) ;
        }
        vector<vector<int>>visited(r,vector<int>(c,0) );
        while(!q.empty()){
            int sz = q.size() ;
            while(sz--){
                auto [x,y] = q.front() ;
                q.pop() ;
                if(x==r-1) return true ;
                visited[x][y] = 1 ;
                
                for(int itr = 0 ; itr < 4; itr ++){
                    int xx = x + dx[itr] , yy = y + dy[itr] ;
                    if(xx>=0 and yy>=0 and xx < r and yy < c and grid[xx][yy] == 0 and visited[xx][yy] == false)    
                    {
                        visited[xx][yy] = true;
                        q.push({xx,yy}) ;
                    }
                }
            }
        }
        return false ; 
    }
    bool isPossible(int r, int c , vector<vector<int>>& cells , int ind ){
        vector<vector<int>>grid;
        grid.resize(r,vector<int>(c,0) );
        for(int i = 0 ; i <= ind ; i ++ ){
            int x = cells[i][0], y = cells[i][1] ;
            grid[x][y] = 1 ; //water filled !
        }
        return solve(grid,r,c);
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        for(auto & vec : cells){
            --vec[0] ; --vec[1] ;
        }
        int lo = 1 , hi = cells.size() ;
        int maxi = 0 ;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(isPossible(row,col,cells,mid-1)){
                maxi = mid ;
                lo = mid +  1 ;
            }
            else hi = mid - 1 ;
        }
        return maxi ;
    }
};