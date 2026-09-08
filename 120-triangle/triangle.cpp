class Solution {
public:
    int minimumtotal(vector<vector<int>>& triangle,int i,int curr,vector<vector<int>>&dp){
        if(i==triangle.size()-1){
            return triangle[i][curr];
        }
        //min(i,i+1)
        if(dp[i][curr]!=INT_MIN) return dp[i][curr];
       return dp[i][curr] = triangle[i][curr]+min(minimumtotal(triangle,i+1,curr,dp),minimumtotal(triangle,i+1,curr+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n+1,INT_MIN));
        return minimumtotal(triangle,0,0,dp);
    }
};