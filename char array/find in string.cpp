#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1="akhilesh";
    string s2="ak";
    if(s1.contains(s2)){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}