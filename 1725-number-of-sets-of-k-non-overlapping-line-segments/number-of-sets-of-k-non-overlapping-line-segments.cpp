class Solution {
public:
    const int MOD = 1e9 + 7;

    int totalNoOfSets(int n, int s, int mid, int k, vector<vector<int>>& dp) {

        if (s == k)
            return 1;

        if (s > k || mid >= n)
            return 0;
        
        if (n - mid - 1 < k - s)
            return 0;

        if (dp[s][mid] != -1)
            return dp[s][mid];

        long long ans = 0;

        // Skip current point
        ans = totalNoOfSets(n, s, mid + 1, k, dp);

        // Take a segment starting at mid
        for (int end = mid + 1; end < n ; end++) {
            ans = (ans + totalNoOfSets(n, s + 1, end, k, dp)) % MOD;
        }

        return dp[s][mid] = ans%MOD;
    }

    int numberOfSets(int n, int k) {
        if (k >= n)
            return 0;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));

        return totalNoOfSets(n, 0, 0, k, dp);
    }
};