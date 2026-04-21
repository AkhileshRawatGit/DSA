#include<iostream>
#include<vector>
using namespace std;
int lps(string &s) {
        int n=s.size();
        vector<int>lps(n,0);
        int pre=0;
        int suff=1;
        while(suff<n){
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<lps(s);
}