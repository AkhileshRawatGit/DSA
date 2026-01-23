#include<iostream>
using namespace std;

int convertDecimal(string str){
    int num=0, pow=1;
    int s=str.size();
    for(int i=s-1;i>=0;i--){
        if(str[i]=='1'){
            num+=pow;
        }
        pow*=2;
    }
    return num;
}
int main(){
    string s;
    cout<<"enter binary number: ";
    cin>>s;
    cout<<convertDecimal(s);
    return 0;
}