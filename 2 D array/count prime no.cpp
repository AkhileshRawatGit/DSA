#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
        if(n==3){
            cout<<count+1;
        }
        else{
        for(int i=2;i<n;i++){
            if(i%2!=0){
                count++;
            }
        }
        cout<< count;
        }
    return 0;
}