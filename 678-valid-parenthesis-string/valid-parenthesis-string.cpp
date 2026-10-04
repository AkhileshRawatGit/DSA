class Solution {
public:

    bool check(string &s,int ind, int count, vector<vector<int>>&dp){
        if(ind<0){
            return count==0;
        }
        if(count<0) return false;

        if(dp[ind][count]!=-1) return dp[ind][count];
        if(s[ind]==')'){
            return dp[ind][count] =check(s,ind-1,count+1,dp);
        }
        if(s[ind]=='('){
            return dp[ind][count] =check(s,ind-1,count-1,dp);
        }
        if(s[ind]=='*'){
            return dp[ind][count]= check(s,ind-1,count+1,dp)||(check(s,ind-1,count-1,dp))||(check(s,ind-1,count,dp));
        }
        return dp[ind][count]=false;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return check(s,s.size()-1,0,dp);
    }
};