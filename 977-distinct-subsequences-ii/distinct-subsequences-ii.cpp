class Solution {
public:
    const int MOD=1e9 + 7;
    int totalSubsequence(string&s,int i,vector<unsigned int>&dp){
        if(dp[i]!=-1) return dp[i];
        int result=1;
        for(int k=0;k<i;k++){
            if(s[i]!=s[k]){
               result= (result+totalSubsequence(s,k,dp))%MOD;
            }
        }
        return dp[i]= result;
    }
    int distinctSubseqII(string s) {
        vector<unsigned int>dp(s.size(),-1);
        int result=0;
        for(int i=0;i<s.size();i++){
            result= (result+totalSubsequence(s,i,dp))%MOD;
        }
        return result;
    }
};