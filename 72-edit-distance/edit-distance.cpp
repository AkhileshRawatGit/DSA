class Solution {
public:
    int minDist(int n,int m,string&word1,string&word2,vector<vector<int>>&dp){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(word1[n-1]==word2[m-1]){
            return dp[n][m]= minDist(n-1,m-1,word1,word2,dp);
        }
        else{
            int deleted=1+minDist(n,m-1,word1,word2,dp);
            int inserted=1+minDist(n-1,m,word1,word2,dp);
            int replaced=1+minDist(n-1,m-1,word1,word2,dp);
            return dp[n][m]=min(deleted,min(inserted,replaced));
        }
    }

//bottom up 
//dp[i][j]=dp[i-1][j-1]
//dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]))
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //return minDist(n,m,word1,word2,dp);
        //column zero
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};