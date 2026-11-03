class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        mp[0]=-1;
        for(int i=0;i<prefix.size();i++){
            if(mp.find(prefix[i]%k)!=mp.end()){
                if((i-mp[prefix[i]%k])>=2) return true;
            }
            else mp[prefix[i]%k]=i;
        }
        return false;
    }
};