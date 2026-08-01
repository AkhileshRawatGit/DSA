class Solution {
public:
    int eggDrop(int egg,int floor,vector<vector<int>>&dp){
        if(egg==1) return floor;
        if(floor==0) return 0;
        if(dp[floor][egg]!=-1) return dp[floor][egg];
        int answer=INT_MAX;
        for(int i=1;i<=floor;i++){
            int result=1+max(eggDrop(egg-1,i,dp),eggDrop(egg,floor-i,dp));
            answer=min(result,answer);
        }
        return dp[floor][egg]=answer;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return eggDrop(2,n,dp)-1;
    }
};