class Solution {
public:
    long long reachEnd(vector<int>&nums, long long ind,vector<int>&dp){
        if(ind>=nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long ans=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
                long long count=1+reachEnd(nums,ind+i,dp);
                ans=min(ans,count);
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& nums) {
        long long ind=0;
        vector<int>dp(nums.size()+1,-1);
        return reachEnd(nums,ind,dp);      
    }
};