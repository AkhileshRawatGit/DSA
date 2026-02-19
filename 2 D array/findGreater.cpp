#include<iostream>
#include<vector>
using namespace std;
void findGreater(vector<int>arr,vector<int>&res,int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
            res[i]=count;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>res(n);
    findGreater(arr,res,n);
    for(auto i: res){
        cout<<i<<" ";
    }
    return 0;
}