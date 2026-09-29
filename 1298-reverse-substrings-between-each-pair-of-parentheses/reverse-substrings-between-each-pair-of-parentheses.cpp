class Solution {
public:
    string reverseParentheses(string s) {
        
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                string dummy="";
                while(st.top()!='('){
                    dummy+=st.top();
                    st.pop();
                }
                st.pop();
                //reverse(dummy.begin(),dummy.end());
                for(int j=0;j<dummy.size();j++){
                    st.push(dummy[j]);
                }
            }
            else st.push(s[i]);
        }
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};