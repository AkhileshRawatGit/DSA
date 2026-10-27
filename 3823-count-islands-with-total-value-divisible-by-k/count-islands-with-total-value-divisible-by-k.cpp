class Solution {
public:
    long long dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j]==0) return 0;
        if(visited[i][j]) return 0;
        visited[i][j]=true;
        //up+down+left+right
        return grid[i][j]+dfs(grid,i-1,j,visited)+dfs(grid,i+1,j,visited)+dfs(grid,i,j-1,visited)+dfs(grid,i,j+1,visited);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
       int n=grid.size();
       int m=grid[0].size();
       int count=0;
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                if(!visited[i][j]){
                    long long a=dfs(grid,i,j,visited);
                    if(a%k==0) count++;
                }
            }
        }
       } 
       return count;
    }
};