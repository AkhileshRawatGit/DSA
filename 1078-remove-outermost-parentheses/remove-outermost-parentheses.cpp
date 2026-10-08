class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        int open=0;
        int close=0;
        unordered_map<int,int>mp;
        for(int j=0;j<s.size();j++){
            if(s[j]=='(') open++;
            else close++;

            if(open==close){
                mp[i]++;
                mp[j]++;
                i=j+1;
            }
        }
        string res="";
        for(int i=0;i<s.size();i++){
            if(mp.find(i)==mp.end()){
                res+=s[i];
            }
        }
        return res;
    }
};