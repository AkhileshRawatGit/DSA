#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int m=n;
    for(int i=1;i<n;i++){
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<j;
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int k=2;k<=i;k++){
            cout<<" ";
        }
        for(int j=1;j<=2*m-1;j++){
            cout<<j;
    }
    m--;
    cout<<endl;
    }
    return 0;
}