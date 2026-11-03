class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int miniMoves=0;
        for(int i=0;i<nums.size();i++){
            miniMoves+=(maxi-nums[i]);
        }
        return miniMoves;
    }
};