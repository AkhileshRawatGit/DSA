#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"times rotate: ";
    cin>>k;

    reverse(arr.begin(),arr.begin()+n-k);
    reverse(arr.begin()+n-k,arr.end());
    reverse(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}