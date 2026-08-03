class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum=currSum+nums[i];
            ans=max(ans,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return ans;
    }
};