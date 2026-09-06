class Solution {
public:
    int Distince(string&s,string&t,int i,int j,vector<vector<unsigned int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=Distince(s,t,i-1,j-1,dp)+Distince(s,t,i-1,j,dp);
        }
        else return dp[i][j]=Distince(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned int>>dp(n,vector<unsigned int>(m,-1));
        return Distince(s,t,s.size()-1,t.size()-1,dp);
    }
};