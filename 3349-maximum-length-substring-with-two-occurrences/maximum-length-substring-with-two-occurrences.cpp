class Solution {
public:
    bool check(string s){
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto&i:mp){
            if(i.second>2) return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        int length=0;
        for(int i=0;i<s.size();i++){
            string a="";
            for(int j=i;j<s.size();j++){
                a+=s[j];
                if(check(a)){
                    length=max(length,(int)a.size());
                }
            }
        }
        return length;
    }
};