class Solution {
public:
    bool check(int i,int j, string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int findMinCut(int i, int n, string& s,vector<int>&dp) {
        if (i == n)
            return 0;
        if(check(i,n,s)){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int cut=INT_MAX;
        for(int k=i;k<n;k++){
            if(check(i,k,s)){
               int cost=1+findMinCut(k+1,n,s,dp);
               cut=min(cut,cost);
            }
            
        }
        return dp[i]=cut;
    }
    int minCut(string s) {
        int i=0;
        int j=s.size()-1;
        vector<int>dp(j+1,-1);
        return findMinCut(i,j,s,dp);
    }
};