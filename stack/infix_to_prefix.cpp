#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+'||ch=='-') return 1;
    else return -1;
}

string infixtoprefix(string s){
    int i=0;
    stack<char>st;
    string ans="";
    reverse(s.begin(),s.end());
    while(i<s.size()){
        char ch=s[i];
        if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0'&& ch<='9')){
            ans+=ch;
        }
        else if(ch==')'){
            st.push(ch);
        }
        else if(ch=='('){
            while(!st.empty()&& st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
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
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=infixtoprefix(s);
    cout<<ans;
    return 0;
}