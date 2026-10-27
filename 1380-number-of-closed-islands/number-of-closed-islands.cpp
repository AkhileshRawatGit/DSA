class Solution {
public:
    bool dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        
        if(grid[i][j]==1) return true;
        if(visited[i][j]) return true;
        visited[i][j]= true;

        //left
            bool left=dfs(grid,i,j-1,visited);
        //right
        bool right=dfs(grid,i,j+1,visited);

        //up 
        bool up=dfs(grid,i-1,j,visited);
        
        //down
        bool down=dfs(grid,i+1,j,visited);
        if(left==true && right==true && up==true && down ==true) return true;
        else return false;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    if(!visited[i][j] && dfs(grid,i,j,visited)) count++;
                }
            }
        }
        return count;
    }
};