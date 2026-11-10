class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            int k=i+1;
            int j=nums.size()-1;
            while(k<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[i],nums[k],nums[j]});
                }
                if(nums[i]+nums[j]+nums[k]>0){
                    j--;
                }
                else k++;
            }
        }
        for(auto&i:ans){
            res.push_back(i);
        }
        return res;
    }
};