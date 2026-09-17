class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st1;
        set<int>st2;
        for(int i=0;i<nums1.size();i++){
            st1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }
        unordered_map<int,int>mp;
        for(auto&i:st1){
            mp[i]++;
        }
        for(auto&i:st2){
            mp[i]++;
        }
        vector<int>res;
        for(auto&i:mp){
            if(i.second==2) res.push_back(i.first); 
        }
        return res;

    }
};