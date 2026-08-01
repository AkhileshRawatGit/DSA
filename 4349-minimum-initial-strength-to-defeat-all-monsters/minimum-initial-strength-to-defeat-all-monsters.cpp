class Solution {
public:
    long long solve(int i,int n,vector<int>& monsters,vector<long long>& diff){
        if(i==n-1){
            return max((long long)0,(long long)monsters[i]-diff[i]);
        }
        long long need=max((long long)0,(long long)monsters[i]-diff[i]);
        long long next=solve(i+1,n,monsters,diff);
        if(next>0){
            need = max(need, (long long)monsters[i] + next);
        }
        return need;
    }
    
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        vector<long long>diff(monsters.size()+1,0);
        for(int i=0;i<boosts.size();i++){
            diff[boosts[i][0]]+=boosts[i][2];
            diff[boosts[i][1]+1]-=boosts[i][2];
        }
        for(int i=1;i<diff.size();i++){
            diff[i]=diff[i]+diff[i-1];
        }
        return solve(0,monsters.size(),monsters,diff);
    }
};