class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        while(mp.size()>0){
            vector<int>dummy;
            for(auto&i:mp){
                dummy.push_back(i.first);
                mp[i.first]--;
            }
            sort(dummy.begin(),dummy.end());
            for(int i=0;i<dummy.size();i++){
                ans.push_back(dummy[i]);
            }
            for(auto it = mp.begin(); it != mp.end(); ){
                if(it->second == 0)
                    it = mp.erase(it);
                else
                    ++it;
            }
        }
        return ans;
    }
};