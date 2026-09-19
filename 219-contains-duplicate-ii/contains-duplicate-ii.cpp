class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        for(auto&i:mp){
            for(int j=1;j<i.second.size();j++){
                if(abs(i.second[j]-i.second[j-1])<=k) return true;
            }
        }
        return false;
    }
};