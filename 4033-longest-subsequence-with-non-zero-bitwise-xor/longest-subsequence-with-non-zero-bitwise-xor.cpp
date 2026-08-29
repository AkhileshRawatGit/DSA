class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int a=0;
        bool nonzero=false;
        for(int i=0;i<nums.size();i++){
            nonzero |=nums[i]>0;
            a=a^nums[i];
        }
        if(a!=0) return nums.size();
        if(nonzero) return nums.size()-1;
        return 0;

    }
};