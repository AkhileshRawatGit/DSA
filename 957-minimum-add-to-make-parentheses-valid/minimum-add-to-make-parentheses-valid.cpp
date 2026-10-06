class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0) st.push(s[i]);

            else if(s[i]==')' && st.top()=='(') st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};