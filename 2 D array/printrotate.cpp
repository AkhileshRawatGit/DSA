#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a row size: ";
    cin>>n;
    int m;
    cout<<"Enter a coloum size: ";
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Rotate an array";
    for (int i = 0; i <n; i++) {
            int temp;
            for (int j =i; j <m; j++) {
                temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    for(int i=0;i<n;i++){
            int l=0;
            int r=n-1;
            while(l<r){
                int temp=arr[i][l];
                arr[i][l]=arr[i][r];
                arr[i][r]=temp;
                l++;
                r--;
            }
        }
        // for(int i=0;i<n;i++){
        //     int t=0;
        //     int d=n-1;
        //         int temp=arr[t][i];
        //         arr[t][i]=arr[d][i];
        //         arr[d][i]=temp;
        //         t++;
        //         d--;
        // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int s = 0;
        int e = row * col - 1;
        int mid = s + (e - s) / 2;
        while (s <=e) {
            int element = matrix[mid / col][mid % col];
            if (element == target) {
                return 1;
            } else if (element < target) {
                s = mid + 1;
            } else if (element > target) {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }