class Solution {
public:
// @3ba2ii
    int lsg(string& text1, string& text2, int n, int m,
            vector<vector<int>>& dp) {
        if (n == 0 || m == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] = 1 + lsg(text1, text2, n - 1, m - 1, dp);
        } else {
            return dp[n][m] = max(lsg(text1, text2, n - 1, m, dp),
                                  lsg(text1, text2, n, m - 1, dp));
        }
    }

    // dp[i][j]=1+dp[i-1][j-1];
    // dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        //int s = min(n + 1, m + 1);
        vector<int> dp(m+1, 0);
        for (int i = 1; i <= n; i++) {
            int prev = 0;
            for (int j = 1; j <= m; j++) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = 1 + prev;
                } else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[m];
    }
};