class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int x,
            vector<vector<vector<int>>>& dp) {

        if(i < 0 || j < 0 ||
           i >= grid.size() || j >= grid[0].size())
            return INT_MAX;

        x ^= grid[i][j];

        if(dp[i][j][x] != -1)
            return dp[i][j][x];

        if(i == grid.size()-1 && j == grid[0].size()-1)
            return dp[i][j][x] = x;

        return dp[i][j][x] = min(
            dfs(grid, i, j+1, x, dp),
            dfs(grid, i+1, j, x, dp)
        );
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int MAX_XOR = 1024;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(MAX_XOR, -1))
        );

        return dfs(grid, 0, 0, 0, dp);
    }
};