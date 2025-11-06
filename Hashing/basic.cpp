#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int hash[12]={0};
    for(int i=0;i<n;i++){
        hash[arr1[i]]=hash[arr1[i]]+1;
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int num;
        cin>>num;
    }
    for(int i=1;i<=q;i++){
        cout<<hash[i];
    }
    return 0;
}