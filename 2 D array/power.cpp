#include<iostream>
using namespace std;
long fastpower(int a,int b,int n){
    long res=1;
    while(b>0){
        if(b&1){
            res=(res*(a)%n)%n;
        }
        a=((a)%n*(a)%n)%n;
        b=b>>1;
    }
    return res;
}
int main(){
    int n;
    int m;
    int c;
    cin>>n>>m>>c;
    cout<<fastpower(n,m,c);
    return 0;
}