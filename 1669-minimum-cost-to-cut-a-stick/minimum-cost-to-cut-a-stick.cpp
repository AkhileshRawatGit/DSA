class Solution {
public:
    int findMinCost(int startIndex, int endIndex, int rodStart,int rodEnd, vector<int>&cuts
    ,vector<vector<int>>&dp){

        if(startIndex>endIndex) return 0;
        //try all possible way
        if(dp[startIndex][endIndex]!=-1) return dp[startIndex][endIndex];
        int result=INT_MAX;
        for(int i=startIndex;i<=endIndex;i++){
            int answer= (rodEnd-rodStart)+findMinCost(startIndex,i-1,rodStart,cuts[i],cuts,dp)+findMinCost(i+1,endIndex,cuts[i],rodEnd,cuts,dp);
            result=min(result,answer);
        }
        return dp[startIndex][endIndex]= result;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return findMinCost(0,cuts.size()-1,0,n,cuts,dp);
    }
};