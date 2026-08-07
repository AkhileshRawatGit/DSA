class Solution {
public:
    int minimumSum(int i, int j, int n, int m, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        if (i == n - 1 && j>=0 && j<m)
            return matrix[i][j];

        if (i >= n || j < 0 || j >= m)
            return INT_MAX;

        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int ans = INT_MAX;
        int left = minimumSum(i + 1, j - 1, n, m, matrix,dp);
        if (left == INT_MAX) {
            left = INT_MAX;
        } else
            left = matrix[i][j] + left;

        int middle = minimumSum(i + 1, j, n, m, matrix,dp);
        if (middle == INT_MAX) {
            middle = INT_MAX;
        } else
            middle = matrix[i][j] + middle;

        int right = minimumSum(i + 1, j + 1, n, m, matrix,dp);
        if (right == INT_MAX) {
            right = INT_MAX;
        } else
            right = matrix[i][j] + right;

        ans = min(left, min(middle, right));
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int result = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++) {
            result = min(result, minimumSum(0, i, n, m, matrix,dp));
        }
        return result;
    }
};