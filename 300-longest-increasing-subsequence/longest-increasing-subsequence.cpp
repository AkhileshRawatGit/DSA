class Solution {
public:
    // int longest(vector<int>& nums, int n,vector<int>&dp) {
    //     if (n == 0)
    //         return 0;

    //     if(dp[n]!=-1) return dp[n];
    //     int ans = 1;
    //     for (int i = 0; i < n - 1; i++) {
    //         if (nums[n - 1] > nums[i]) {
    //             ans = max(ans, 1 + longest(nums, i+1,dp));
    //         }
    //     }
    //     return dp[n]=ans;
    // }
    int lower_bound(vector<int>&dp,int target){
        int s=0;
        int e=dp.size();
        while(s<e){
            int mid=s+(e-s)/2;
            if(dp[mid]>=target){
                e=mid;
            }
            else s=mid+1;
        }
        return s;
    }
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        vector<int>dp(1,nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int index=lower_bound(dp,nums[i]);
            if(index==dp.size()){
                dp.push_back(nums[i]);
            }
            else if(nums[i]<dp[index]) dp[index]=nums[i];
        }
        return dp.size();
    }
};