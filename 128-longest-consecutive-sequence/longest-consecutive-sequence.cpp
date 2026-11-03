class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        unordered_map<int,int>mp;
        for(auto&i:st){
            mp[i]++;
        }
        int res=1;
        int count=0;
        for(auto&i:st){
            if(mp.find(i+1)!=mp.end()){
                count++;
            }
            else{
                res=max(res,count+1);
                count=0;
            }
        }
        return max(res,count+1);
    }
};