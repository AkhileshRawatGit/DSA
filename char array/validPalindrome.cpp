#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isAlphanumeric(char ch){
    if((ch>='0' && ch<='9')||(tolower(ch)>='a' && tolower(ch)<='z')) return true;
    else return false;
}
bool validPalindrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(!isAlphanumeric(s[i])){
            i++;
            continue;
        }
        if(!isAlphanumeric(s[j])){
            j--;
            continue;
        }
        if(tolower(s[i])!=tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<validPalindrome(s);
    return 0;
}