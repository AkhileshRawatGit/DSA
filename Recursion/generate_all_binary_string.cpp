#include<iostream>
#include<vector>
using namespace std;
void binarystring(string str,string s,vector<string>&ans,int ind){
    int n=str.size();
    if(ind==n){
        ans.push_back(s);
        return;
    }
    if(str[ind]!='?'){
        binarystring(str,s+str[ind],ans,ind+1);
    }
    else{
    binarystring(str,s+'0',ans,ind+1);
    binarystring(str,s+'1',ans,ind+1);
    }
}
vector<string> binaryStrings(string &str) {
    // Write your code here.
    string s="";
    vector<string>ans;
    binarystring(str,s,ans,0);
    return ans;
}
int main(){
    string s;
    cout<<"enter the string: ";
    cin>>s;
    vector<string>ans=binaryStrings(s);
    int n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}