class Solution {
public:
    int longest(vector<int>& nums, int n,vector<int>&dp) {
        if (n == 0)
            return 0;

        if(dp[n]!=-1) return dp[n];
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[n - 1] > nums[i]) {
                ans = max(ans, 1 + longest(nums, i+1,dp));
            }
        }
        return dp[n]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        vector<int>dp(nums.size()+1,-1);
        for (int i = 1; i <= nums.size(); i++) {
            result = max(result, longest(nums, i,dp));
        }
        return result;
    }
};