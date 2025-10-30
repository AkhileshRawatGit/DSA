#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter array size";
    cin>>size;
    int arr[size];
    cout<<"Input array element:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }

    }
    cout<<"Maximum number"<<max<<endl;
    cout<<"Minimum number"<<min;
    return 0;
}