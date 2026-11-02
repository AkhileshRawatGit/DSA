class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        vector<int>res(nums.size());
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            res[i]=res[i-1]+nums[i];
        }
        int count=0;
        for(int i=0;i<res.size();i++){
            if(mp.find(res[i]-k)!=mp.end()){
                count+=mp[res[i]-k];
            }
            mp[res[i]]++;
        }
        return count;
    }
};