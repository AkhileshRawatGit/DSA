class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count++;
            if(s[i]==')'){
                ans=max(ans,count);
                count--;
            }
        }
        return ans;
    }
};