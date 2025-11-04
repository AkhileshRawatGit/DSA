#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter row size: ";
    cin>>n;
    cout<<"Enter coloum size: ";
    int m;
    cin>>m;
    int k;
    cout<<"find kth element: ";
    cin>>k;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Input Matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    // int temp=arr[0][0];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]<temp){
    //             temp=arr[i][j]+arr[];
    //         }
    //     }
    // }
    // cout<<temp+(k-1);
    vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(arr[i][j]);
        }
    }
        sort(ans.begin(),ans.end());
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=ans[t];
                t++;
            }
            
        }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<arr[(k-1)/n][(k-1)%n];
    return 0;
}
//16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}