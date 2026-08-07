class Solution {
public:
    int minimumSum(int i, int j, int n, int m, vector<vector<int>>& grid,
                   vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1)
            return grid[i][j];
        if (i == n && j < m)
            return INT_MAX;
        if (j == m && i < n)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];
        // min(curr+down, curr+right)
        int ans = 0;
        if ((i < n && i >= 0) || (j >= 0 && j < m)) {
            int down = minimumSum(i + 1, j, n, m, grid, dp);
            if (down == INT_MAX)
                down = INT_MAX;
            else
                down = grid[i][j] + down;

            int right = minimumSum(i, j+1, n, m, grid, dp);
            if (right == INT_MAX)
                right = INT_MAX;
            else
                right = grid[i][j] + right;

            ans = min(down, right);
        }
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minimumSum(i, j, n, m, grid, dp);
    }
};