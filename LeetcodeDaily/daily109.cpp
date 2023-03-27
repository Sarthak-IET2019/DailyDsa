// minimum path sum

class Solution {
public: 
    int solve(vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m,int row,int col){

        if(row>=n or col>=m) return INT_MAX;
        if(row==n-1 and col==m-1) return grid[n-1][m-1];
        if(dp[row][col]!=-1) return dp[row][col];

        int right = solve(grid,dp,n,m,row,col+1);
        int down = solve(grid,dp,n,m,row+1,col);

        int best = min(right,down);

        return dp[row][col]=grid[row][col]+best;
    }
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,dp,n,m,0,0);
        
    }
};