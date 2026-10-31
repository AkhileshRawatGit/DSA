class Solution {
public:
// direction 0 means right 1 mean down
    const int MOD = 1000000007;
    int ValidPath(vector<vector<int>>&grid,int i,int j,int n,int m,int dir,vector<vector<vector<int>>>&dp){
        if(i<0 || j<0 || i==n || j==m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        //down
        if(dir==0 && grid[i][j]==1)
            return dp[i][j][dir]=ValidPath(grid,i+1,j,n,m,1,dp);

        //right
        else if(dir==1 && grid[i][j]==1)
            return dp[i][j][dir]= ValidPath(grid,i,j+1,n,m,0,dp);
        
        else return dp[i][j][dir]=(ValidPath(grid,i,j+1,n,m,0,dp)+ValidPath(grid,i+1,j,n,m,1,dp))%MOD;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(2,-1)));
        int right=ValidPath(grid,0,1,grid.size(),grid[0].size(),0,dp);
        int down=ValidPath(grid,1,0,grid.size(),grid[0].size(),1,dp);
        return (right+down)%MOD;
    }
};