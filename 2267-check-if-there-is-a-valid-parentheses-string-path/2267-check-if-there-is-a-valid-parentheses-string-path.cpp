class Solution {

public:
    int t[101][101][201];                              //Dp array 
    bool helper(vector<vector<char>>& grid,int open,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size())   //Base Case  - out of bound
            return false;
        
        
        if(i==grid.size()-1 && j==grid[0].size()-1) // reached the n-1,m-1 cell
            {
                if(open==1 && grid[i][j]==')')   // true only if last element is '{' and number of open brackets left if 1 
                    return t[i][j][open]=true;  
                else
                    return t[i][j][open]=false;      // false otherwise
            }
        
        if(t[i][j][open]!=-1)   // if calculated previously 
            return t[i][j][open];
        
        if(grid[i][j]=='(')  // if we encounter an open bracket
        {
            return  t[i][j][open]=helper(grid,open+1,i+1,j) || helper(grid,open+1,i,j+1);  // moving down and right
        }
        else     // if we encounter an open bracket
        {
            if(open<=0)                          //when closing bracket is encountered without any previous open bracket
                return t[i][j][open]=false;
                                                                                   // open count will decrease when closed bracket is encountered
                return t[i][j][open]=helper(grid,open-1,i+1,j) || helper(grid,open-1,i,j+1);   // moving down and right
        }
    }
    bool hasValidPath(vector<vector<char>> grid) {
        memset(t,-1,sizeof(t));               // intializing the dp array
        return helper(grid,0,0,0);           // initially  i=0 , j=0 i.e; starting point and open is also 0
    }
};