class Solution {
public:
    const int MOD=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>count(32,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){
                    count[j]++;
                }
            }
        }
        long long result=0;
        while(k--){
            long long curr=0;
            for(int i=0;i<32;i++){
                if(count[i]>0){
                    count[i]--;
                    curr=curr|(1<<i);
                }
            }
            result=(result+(curr*curr))%MOD;
        }
        return result;
    }
};