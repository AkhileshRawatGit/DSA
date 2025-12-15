#include<iostream>
using namespace std;
void swap(int p,int q){
    int z;
    z=p;
    p=q;
    q=z;
    cout<<p;
    cout<<q;
}
int main(){
    int a=5,b=4;
    swap(a,b);
    cout<<a;
    cout<<b;
    return 0;
}

