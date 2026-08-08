class Solution {
public:
    int findMaximum(int r1, int c1, int r2, int c2, int n, int m,
                    vector<vector<int>>& grid ,vector<vector<vector<vector<int>>>>&dp) {
        if (c1 < 0 || c2 < 0 || r1 >= n || c1 >= m || r2 >= n || c2 >= m)
            return INT_MIN;
        if (r1 == n - 1) {
            int value = grid[r1][c1];
            if (c1 != c2) {
                value += grid[r2][c2];
            }
            return value;
        }

        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        int value = grid[r1][c1];

        if (c1 != c2) {
            value += grid[r2][c2];
        }
        int ll = findMaximum(r1 + 1, c1 - 1, r2 + 1, c2 - 1, n, m, grid,dp);
        int lb = findMaximum(r1 + 1, c1 - 1, r2 + 1, c2, n, m, grid,dp);
        int lr = findMaximum(r1 + 1, c1 - 1, r2 + 1, c2 + 1, n, m, grid,dp);

        int bl = findMaximum(r1 + 1, c1, r2 + 1, c2 - 1, n, m, grid,dp);
        int bb = findMaximum(r1 + 1, c1, r2 + 1, c2, n, m, grid,dp);
        int br = findMaximum(r1 + 1, c1, r2 + 1, c2 + 1, n, m, grid,dp);

        int rl = findMaximum(r1 + 1, c1 + 1, r2 + 1, c2 - 1, n, m, grid,dp);
        int rb = findMaximum(r1 + 1, c1 + 1, r2 + 1, c2, n, m, grid,dp);
        int rr = findMaximum(r1 + 1, c1 + 1, r2 + 1, c2 + 1, n, m, grid,dp);

        int pick = max({ll, lb, lr, bl, bb, br, rl, rb, rr});

        if (pick == INT_MIN)
            return dp[r1][c1][r2][c2]= INT_MIN;

        return dp[r1][c1][r2][c2]=  pick+value;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
        int answer = findMaximum(0, 0, 0, m - 1, n, m, grid,dp);
        if (answer == INT_MIN)
            return 0;
        return answer;
    }
};