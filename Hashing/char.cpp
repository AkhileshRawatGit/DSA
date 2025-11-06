#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<s;

    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int n;
    cin>>n;
    while (n--)
    {
        /* code */
        char c;
        cin>>c;

        cout<<hash[c-'a'];
    }
    return 0;

}