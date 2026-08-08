class Solution {
public:
    int findAllIncreasingPath(int i, int j, int n, int m,
                              vector<vector<int>>& grid,vector<vector<int>>&dp) {

        if(dp[i][j]!=-1) return dp[i][j];
        long long result = 1;
        if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j]) {
            result += findAllIncreasingPath(i - 1, j, n, m, grid,dp);
        }
        if (i + 1 < n && grid[i + 1][j] > grid[i][j]) {
            result += findAllIncreasingPath(i + 1, j, n, m, grid,dp);
        }
        if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j]) {
            result += findAllIncreasingPath(i, j - 1, n, m, grid,dp);
        }
        if (j + 1 < m && grid[i][j + 1] > grid[i][j]) {
            result += findAllIncreasingPath(i, j + 1, n, m, grid,dp);
        }
        return dp[i][j]=result%1000000007;
    }
    int countPaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        long long answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = (answer + findAllIncreasingPath(i, j, n, m, grid,dp))%1000000007;
            }
        }
        return answer%1000000007;
    }
};