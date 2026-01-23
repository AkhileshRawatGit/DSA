#include<iostream>
#include<string>
using namespace std;
string convert(int val){
    string s="";
    while(val>0){
        if(val%2==0) s+='0';
        else s+='1';
        val=val/2;
    }
    return s;
}
int main(){
    int val;
    cin>>val;
    cout<<convert(val);
    return 0;
}