#include<iostream>
#include<stack>
using namespace std;
string postfixtoinfix(string s){
    stack<string>st;
    int i=0;
    while(i<s.size()){
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
            string ans='('+s2+s[i]+s1+')';
            st.push(ans);
        }
        i++;
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string ans=postfixtoinfix(s);
    cout<<ans;
    return 0;
}