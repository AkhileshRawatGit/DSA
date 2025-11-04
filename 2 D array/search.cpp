#include<iostream>
using namespace std;
void rowsum(int arr[][3],int r,int c){
    int ans=0;
    int s=0;
    for(int i=0;i<c;i++){
        int sum=0;
        for(int j=0;j<r;j++){
            sum=sum+arr[i][j];
            if(ans<sum){
                ans=sum;
                s=i;
            }
        }
        cout<< sum<<endl;
        sum=0;
    }
    cout<<endl;
    cout<<ans;
    cout<<"row is: "<<s;
}
// void colsum(int arr[][3],int r,int c){
//     for(int j=0;j<c;j++){
//         int sum=0;
//         for(int i=0;i<r;i++){
//             sum=sum+arr[i][j];

//         }
//         cout<< sum<<endl;
//         sum=0;
//     }
// }
// bool search(int arr[][3],int n,int r,int c){
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             if(arr[i][j]==n){
//                 return 1;
//             }
//         }
        
//     }
//     return 0;
// }
int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    // int target;
    // cin>>target;
    // if(search(arr,target,3,3)){
    //     cout<<"found";
    // }
    // else{
    //     cout<<"not found";
    // }

    rowsum(arr,3,3);
    // colsum(arr,3,3);

    return 0;
}