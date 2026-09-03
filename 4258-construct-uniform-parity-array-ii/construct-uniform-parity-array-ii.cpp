class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        if(nums1.size()==1) return true;
        int evenMin=INT_MAX;
        int oddMin=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) evenMin=min(evenMin,nums1[i]);
            if(nums1[i]%2!=0) oddMin=min(oddMin,nums1[i]);
        }
        if(evenMin==INT_MAX || oddMin==INT_MAX) return true;
        if(oddMin<evenMin) return true;
        return false;
    }
};