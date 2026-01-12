#include<iostream>
#include<vector>
using namespace std;
bool palindrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
void subset(string ques,vector<vector<string>>&ans,vector<string>dummy){
    if(ques.size()==0){
        ans.push_back(dummy);
        return;
    }
    for(int i=0;i<ques.size();i++){
        string sub=ques.substr(0,i+1);
        if(palindrome(sub)){
            dummy.push_back(sub);
            subset(ques.substr(i+1),ans,dummy);
            dummy.pop_back();
        }
    }
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    vector<vector<string>>ans;
    vector<string>dummy;
    subset(s,ans,dummy);
    for(auto i:ans){
        cout<<"[";
        for(auto j:i){
            cout<<j<<", ";
        }
        cout<<"]"<<endl;
    }
}