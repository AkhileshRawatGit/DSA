class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int res=1;
        int count=0;
        for(auto&i:mp){
            if(mp.find(i.first+1)!=mp.end()){
                count++;
            }
            else{
                res=max(res,count+1);
                count=0;
            }
        }
        return max(res,count);

    }
};