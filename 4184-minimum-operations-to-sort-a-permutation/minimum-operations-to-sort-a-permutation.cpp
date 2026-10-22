class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int asce=1;
        int dese=1;
        for(int i=1;i<nums.size();i++){
            asce+=(nums[i]==(nums[i-1]+1)%n);
            dese+=(nums[i-1]==(nums[i]+1)%n);
        }
        if(asce==n){
            if(nums[0]==0) return 0;
            int left=n-nums[0];
            int right=1+(nums.back()+1)+1;
            return min(left,right);
        }
        if(dese==n){
            int left=n-nums.back()+1;
            int right=(nums[0]+1)%n+1;
            return min(left,right);
        }
        return -1;
    }
};