#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n;j++){
        if(target==(arr[i]+arr[j])){
            cout<<arr[i]<<arr[j];
        }
    }
    }
    return 0;
}