class Solution {
public:
    long long reachEnd(vector<int>& nums, long long ind, vector<int>& dp) {
        if (ind >= nums.size() - 1)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        long long ans = INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) {
            long long count = 1 + reachEnd(nums, ind + i, dp);
            ans = min(ans, count);
        }
        return dp[ind] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, INT_MAX);
        dp[n - 1] = 0;
        long long ind = n-1;
        while (ind>=0) {
            for (int jump = 1; jump <= nums[ind];jump++) {
                if(ind+jump<n)
                    dp[ind] = min(dp[ind],1+dp[ind+jump]);
            }
            ind--;
        }
        return dp[0];
    }
}
;