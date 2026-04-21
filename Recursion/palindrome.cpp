#include<iostream>
using namespace std;
bool ispalindrome(int a,int b,int c){
    if(a==0){
        return b==c;
    }
    return ispalindrome(a/10,a%10+10*b,c);
}
int main(){
    int a;
    cout<<"enter a number: ";
    cin>>a;

    cout<<ispalindrome(a,0,a);
}