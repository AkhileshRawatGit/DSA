#include<iostream>
#include<stack>
using namespace std;
int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*'|| ch=='/') return 2;
    else if(ch=='+'|| ch=='-') return 1;
    else return -1;
}
string infixToPostfix(string s){
    int i=0;
    string ans="";
    stack<char>st;
    while(i<s.length()){
        char ch=s[i];
        if((ch>='a' && ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0'&& ch<='9')){
            ans+=ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty()&& st.top()!='('){
                ans=ans+st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&& priority(ch)<=priority(st.top())){
                ans+=st.top();
                st.pop();
                
            }
            st.push(ch);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    string ans=infixToPostfix(s);
    cout<<ans;
    return 0;
}
