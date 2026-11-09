class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(k>=nums.size()) return nums.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<nums.size()){
            if(nums[j]==0){
                k--;
            }
            mp[nums[j]]++;
            while(k<0){
                if(nums[i]==0) k++;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};