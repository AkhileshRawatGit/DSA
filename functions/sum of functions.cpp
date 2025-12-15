#include<iostream>
using namespace std;
void add(int,int);
int main(){
    int n,m;
    cout<<"Enter first number: ";
    cin>>n;
    cout<<"Enter second number: ";
    cin>>m;
    add(n,m);
    return 0;
    
}
void add(int p,int q){
    int sum;
    sum=p+q;
    cout<<sum;
}