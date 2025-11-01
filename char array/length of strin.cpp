#include<iostream>
using namespace std;
int main(){
    int size=0;
    char name[20];
    cin>>name;
    for(int i=0;name[i]!='\0';i++){
        
        size++;
    }
    cout<<size;
    return 0;
}