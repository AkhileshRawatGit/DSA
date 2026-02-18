#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int findnearst(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        arr[i]=abs(arr[i]);
    }
    
    int ans=INT_FAST16_MAX;
    int ind=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=ans){
            ans=arr[i];
            ind=i;
        }
    }
    return ind;
}
int main(){
    int n;
    cout<<"Enter the array size";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<arr[findnearst(arr)];
}