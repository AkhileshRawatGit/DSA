class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>ans;
        ans.push(-1);
        int max_len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ans.push(i);
            }
            else{
                ans.pop();
                if(ans.size()==0){
                    ans.push(i);
                }
                else{
                    max_len=max(max_len,i-ans.top());
                }
            }
        }
        return max_len;
    }
};