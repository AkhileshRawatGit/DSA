class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string a=strs[i];
            sort(a.begin(),a.end());
            mp[a].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto&i:mp){
            vector<string>res=i.second;
            ans.push_back(res);
        }
        return ans;
    }
};