class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool flag=false;
        int i=0;
        int j=0;
        int maxi=0;
        int ind=-1;
        while(j<nums.size()){
            if(nums[j]==0){
                if(flag){
                    maxi=max(maxi,j-i-1);
                    i=ind+1;
                }
                else flag=true;
                ind=j;
            }
            j++;
        }
        maxi = max(maxi, j-i-1);
        if(ind==-1) return nums.size()-1;
        return maxi;
    }
};