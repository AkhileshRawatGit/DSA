#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void phoneproblem(vector<string>&s,vector<string>&ans,string dummy, int s1){
    if(s1==0){
        reverse(dummy.begin(),dummy.end());
        ans.push_back(dummy);
        return;
    }
    int n1=s1%10;
    string s2=s[n1];
    int a=s2.size();
    for(int i=0;i<a;i++){
        phoneproblem(s,ans,s2[i]+dummy,s1/10);
    }
}
int main(){
    string s2;
    cin>>s2;
    reverse(s2.begin(),s2.end());
    int n=stoi(s2);
    vector<string>ans;
    vector<string>s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    phoneproblem(s,ans,"",n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}