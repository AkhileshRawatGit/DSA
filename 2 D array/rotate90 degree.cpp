#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter row size: ";
    cin>>n;
    cout<<"Enter coloum size: ";
    int m;
    cin>>m;
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
    // cout<<"transpose Matrix :"<<endl;
    // for(int i =0; i<n; i++){
    //     int temp;
    //     for(int j=i; j<m; j++){
    //         temp=arr[i][j];
    //         arr[i][j]=arr[j][i];
    //         arr[j][i]=temp;
    //     }
    // }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<"90 Degree rotated Matrix :";
    // for(int i=0;i<n;i++){
    // int sr=0;
    // int er=n-1;
    // while(sr<er){
    //     int temp;
            
    //             temp=arr[i][sr];
    //             arr[i][sr]=arr[i][er];
    //             arr[i][er]=temp;
    //             sr++;
    //             er--;
    // }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<"180 Degree rotated Matrix :";
    for(int i=0;i<n;i++){
    int sr=0;
    int er=n-1;
    while(sr<er){
        int temp;
            
                temp=arr[i][sr];
                arr[i][sr]=arr[i][er];
                arr[i][er]=temp;
                sr++;
                er--;
    }
    }
    for(int i=0;i<n;i++){
    int sr=0;
    int er=n-1;
    while(sr<er){
        int temp;
            
                temp=arr[sr][i];
                arr[sr][i]=arr[er][i];
                arr[er][i]=temp;
                sr++;
                er--;
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}