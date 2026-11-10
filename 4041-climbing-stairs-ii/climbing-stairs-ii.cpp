class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 3, LLONG_MAX);

        dp[n] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {

            if (ind + 1 <= n)
                dp[ind] = min(dp[ind],
                    costs[ind] + 1LL + dp[ind + 1]);

            if (ind + 2 <= n)
                dp[ind] = min(dp[ind],
                    costs[ind + 1] + 4LL + dp[ind + 2]);

            if (ind + 3 <= n)
                dp[ind] = min(dp[ind],
                    costs[ind + 2] + 9LL + dp[ind + 3]);
        }

        return dp[0];
    }
};