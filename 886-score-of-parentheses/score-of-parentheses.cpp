class Solution {
public:

    int scoreOfParentheses(string s) {
        int count=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int value=0;
                int inner=st.top();
                st.pop();
                if(inner==0){
                    value=1;
                }
                else{
                    value=2*inner;
                }
                if(st.size()==0){
                    count+=value;
                }
                else st.top()+=value;
            }
        }
        return count;
    }
};