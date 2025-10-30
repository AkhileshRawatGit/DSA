#include<iostream>
using namespace std;
void update(int arr[],int n){
    arr[1]=120;
    cout<<"Updating array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int arr[3]={1,2,3};
    cout<<endl;
    cout<<"Real array element"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr[i];
    }
    update(arr,3);
    cout<<endl;
    cout<<"main function array element"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr[i];
    }
    return 0;
}