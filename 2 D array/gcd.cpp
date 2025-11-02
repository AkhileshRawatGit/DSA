// //euclid algo
// #include<iostream>
// using namespace std;
// int gcd(int a,int b){
//     if(a==0){
//         return b;
//     }
//     if(b==0){
//         return a;
//     }
//     while(a!=b){
//         if(a>b){
//             a=a-b;
//         }
//         else{
//             b=b-a;
//         }
//     }
//     return a;
// }
// int main(){
//     int n;
//     cin>>n;
//     int m;
//     cin>>m;
//     // gcd find
//     cout<<(n*m)/gcd(n,m);
//     return 0;
// }




#include<iostream>
using namespace std;
int euclidalgo(int a,int b){
    if((a<=1)||(b<=1)){
        return 1;
    }
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        if(b>a){
            b=b-a;
        }
    }
    return a;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<(n*m)/euclidalgo(n,m);
    return 0;
}