class Solution {
public:
    static bool comp(vector<int>&first,vector<int>&second){
        if(first[0]==second[0])
            return first[1]>second[1];

        return first[0]<second[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),comp);
        int n=envelopes.size();
        vector<int>dp(1,envelopes[0][1]);
        for(int i=1;i<n;i++){
            auto lowerBound=lower_bound(dp.begin(),dp.end(),envelopes[i][1])-dp.begin();
            if(lowerBound==dp.size()){
                dp.push_back(envelopes[i][1]);
            }
            else dp[lowerBound]=envelopes[i][1];

        }
        return dp.size();
    }
};