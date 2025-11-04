#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout<<"Enter rows: ";
    cin>>n;
    cout<<"Enter coloum: ";
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"before sorting";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    int sr=0;
    for(int j=sr;j<n;j++){
        for(int i=1;i<=m;i++){
            if(arr[0][i-1]>arr[0][i]){
                int temp=arr[0][i-1];
                arr[0][i-1]=arr[0][i];
                arr[0][i]=temp;
            }
        }
    }
    cout<<"after sorting";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}