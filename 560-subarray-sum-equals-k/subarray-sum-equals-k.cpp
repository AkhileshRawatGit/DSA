class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        mp[0]++;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(prefix[i]-k)!=mp.end()){
                count+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};