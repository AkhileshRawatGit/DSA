class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {
        int curr1=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr1=curr1+nums[i];
            maxi=max(maxi,curr1);
            if(curr1<0) curr1=0;
        }

        int curr2=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            curr2=curr2+nums[i];
            
            mini=min(mini,curr2);
            if(curr2>0) curr2=0;
        }
        return max(abs(mini),maxi);
    }
};