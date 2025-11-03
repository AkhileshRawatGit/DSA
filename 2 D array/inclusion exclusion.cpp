#include<iostream>
using namespace std;
//divisible by 5 and 7
int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int count1=n/a;
    int count2=n/b;
    int count3=n/(a*b);
    int total;
    
    total=count1+count2-count3;
    //cout<<total;
    return 0;
}