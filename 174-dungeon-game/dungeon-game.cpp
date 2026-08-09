class Solution {
public:
    int calculate(vector<vector<int>>& dungeon,
                  int i, int j,
                  int n, int m,
                  vector<vector<int>>& dp) {

        if (i >= n || j >= m)
            return INT_MAX;

        if (i == n - 1 && j == m - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = calculate(dungeon, i + 1, j, n, m, dp);
        int right = calculate(dungeon, i, j + 1, n, m, dp);

        int next = min(down, right);

        int requiredHP = next - dungeon[i][j];

        return dp[i][j] = max(1, requiredHP);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return calculate(dungeon, 0, 0, n, m, dp);
    }
};