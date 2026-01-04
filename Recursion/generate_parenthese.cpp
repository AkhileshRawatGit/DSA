#include<iostream>
#include<vector>
using namespace std;
void generateParenthese(int n,string s,vector<string>&ans,int open,int close){
    if(open == n && close == n){
        ans.push_back(s);
        return;
    }
    if(open<n){
        generateParenthese(n,s+'(',ans,open+1,close);
    }
    if(close<open){
        generateParenthese(n,s+')',ans,open,close+1);
    }
}
    vector<string> generate(int n) {
    vector<string>ans;
    string s="";
    generateParenthese(n,s,ans,0,0);
    return ans;
    }
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<string>ans=generate(n);
    int size1=ans.size();
    for(int i=0;i<size1;i++){
        string a=ans[i];
        if(a[0]==')') continue;
        else if(a[n*n-1]=='(') continue;
        else{
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}