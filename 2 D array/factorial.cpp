
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m=47;
    long long fact=1;
    for(int i=1;i<=n;i++){
        fact=(fact*(i)%m)%m;
    }
    cout<<fact;
    return 0;
}