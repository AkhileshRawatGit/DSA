class Solution {
public:
    int findMaximum(int r1,int c1,int r2, int n, vector<vector<int>>&grid,
    vector<vector<vector<int>>>&dp){
        int c2=(r1+c1)-r2;
        //base case
        if(r1>=n || c1>=n || r2>=n || c2>=n) return INT_MIN;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==n-1 && c1==n-1) return grid[n-1][n-1];

        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int charries=grid[r1][c1];
        if(r1!=r2 && c1!=c2){
            charries+=grid[r2][c2];
        }
       
       //dd dr rd rr
       int dd=findMaximum(r1+1,c1,r2+1,n,grid,dp);
       int dr=findMaximum(r1+1,c1,r2,n,grid,dp);
       int rd=findMaximum(r1,c1+1,r2+1,n,grid,dp);
       int rr=findMaximum(r1,c1+1,r2,n,grid,dp);

       int result=max({dd,dr,rd,rr});

       if(result==INT_MIN) return dp[r1][c1][r2]= INT_MIN;

       return dp[r1][c1][r2]= result+charries;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int answer= findMaximum(0,0,0,grid.size(),grid,dp);
        if(answer==INT_MIN) return 0;
        return answer;
    }
};