#include<iostream>
#include<stack>
using namespace std;
string prifix_to_infix(string s){
    stack<string>st;
    int i=s.size()-1;
    while(i>=0){
        if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z')||(s[i]>='0'&& s[i]<='9')){
            string s1="";
            s1+=s[i];
            st.push(s1);
        }
        else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string ans='('+s1+s[i]+s2+')';
            st.push(ans);
        }
        i--;
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=prifix_to_infix(s);
    cout<<ans;
    return 0;
}