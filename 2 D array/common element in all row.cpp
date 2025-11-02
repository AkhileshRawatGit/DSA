#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout<<"Enter rows :";
    cin>>n;
    cout<<"Enter coloum: ";
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    int sr=0;//0 0 0 1 0 0 0 0 0 1 0 1
    while(sr<n){
        for(int i=sr;i<=sr;i++){
        for(int j=0;j<m;i++){
            if(arr[i][j]==0){
                break;
            }
            else{
                cout<<i;
            }
        }
    }
    sr++;
}
// while(sr<row){
//     for(int i=sr;i<=sr;i++){
//         for(int j=0;j<col;j++){
//             if(arr[i][j]==1){
//                 count++;
                
//             }
//         }
//     }
//     if((count<=max)&&(count>=min)){
//         min=count;
//         count=0;
        
//     }
//     else{
//         count=0;
//     }
//     sr++;
// 	}

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==0){
    //             break;
    //         }
    //         else{
    //             cout<<i;
    //         }
    //     }
    // }
    return 0;
}