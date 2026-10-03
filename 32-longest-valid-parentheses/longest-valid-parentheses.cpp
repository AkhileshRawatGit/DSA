class Solution {
public:
    int longestValidParentheses(string s) {
        int maximum=0;
        int open=0;
        int close=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else close++;
            

            if(open==close) maximum=max(maximum,open+close);

            if(close>open) close=open=0;
        }
        open=0;
        close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            

            if(open==close) maximum=max(maximum,open+close);

            if(open>close) close=open=0;
        }
        return maximum;
    }
};