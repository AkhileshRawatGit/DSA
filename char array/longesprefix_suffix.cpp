#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
string reverse(string s){
  int i=0;
  int j=s.size()-1;
  while(i<j){
    swap(s[i],s[j]);
    i++;
    j--;
    }
  return s;
}
string lps(string s){
    int i=0;
    int j=s.size()-1;
    unordered_map<string,int>mp;
    string s1="";
    string s2="";
    string s3="";
    while(i<j){
        s1+=s[i];
        s2+=s[j];
        s3=reverse(s2);
        if(s1==s3){
            mp[s1]=s1.size();
        }
        i++;
        j--;
    }
    int maxfreq=-1;
    string ans="";
    for(auto i:mp){
        if(i.second>maxfreq){
            maxfreq=i.second;
            ans=i.first;
        }
    }
    return ans;
}
int main(){

    string s;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<lps(s);
    return 0;
}