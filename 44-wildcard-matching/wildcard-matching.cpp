class Solution {
public:
    bool check(string&s,string&p,int n,int m,vector<vector<int>>&dp){
        if(n && m==0) return false;
        if(n==0 && m==0) return true;
        if(n==0){
            for(int i=0;i<m;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[n][m]!=-1) return dp[n][m];

        if(p[m-1]=='?'){
            return dp[n][m]= check(s,p,n-1,m-1,dp);
        }
        else if(p[m-1]=='*'){
            return dp[n][m]= check(s,p,n,m-1,dp) || check(s,p,n-1,m,dp);
        }
        else if(p[m-1]==s[n-1]){
            return dp[n][m]= check(s,p,n-1,m-1,dp);
        }
        else return dp[n][m]= false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return check(s,p,n,m,dp);
    }
};