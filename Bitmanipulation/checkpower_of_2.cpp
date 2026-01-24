#include<iostream>
using namespace std;
bool check(int n){
    if(n<=0) return false;
    else if((n&(n-1))==0) return true;
    else return false;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<check(n);
    return 0;
}