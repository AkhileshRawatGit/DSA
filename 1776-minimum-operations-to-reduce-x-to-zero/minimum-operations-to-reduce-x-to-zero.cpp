class Solution {
public:
    // int minOperationToZero(vector<int>& nums, int x, int left, int right,vector<vector<int>>&dp) {
    //     if (x == 0)
    //         return 0;
    //     if (x < 0)
    //         return INT_MAX;

    //     if (left > right)
    //         return INT_MAX;
        
    //     int l = left;
    //     int r = nums.size() - 1 - right;
    //     if(dp[l][r]!=-1) return dp[l][r];
    //     int leftMost =
    //          minOperationToZero(nums, x - nums[left], left + 1, right,dp);
    //     if(leftMost!=INT_MAX) leftMost++;
    //     int rightMost =
    //         minOperationToZero(nums, x - nums[right], left, right - 1,dp);

    //     if(rightMost!=INT_MAX) rightMost++;
    //     return dp[l][r]=min(leftMost, rightMost);
    // }
    int minOperations(vector<int>& nums, int x) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // int ans = minOperationToZero(nums, x, 0, nums.size() - 1,dp);
        // if (ans == INT_MAX)
        //     return -1;
        // return ans;

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        sum=sum-x;
        if(sum==0) return nums.size();

        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(mp.find(prefix[i]-sum)!=mp.end()){
                ans=max(ans,i-mp[prefix[i]-sum]);
            }
            mp[prefix[i]]=i;
        }
        return ans==-1?-1:nums.size()-ans;
    }
};