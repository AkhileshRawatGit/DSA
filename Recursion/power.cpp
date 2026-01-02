#include<iostream>
using namespace std;
 double ans(double x, long n){
        if(n==0){
            return 1;
        }
        if(n&1) return x*ans(x,n-1);
        else return ans(x*x,n/2);
    }
    double myPow(double x, int n) {
        long N=n;
        if(N<0){
            return 1/(ans(x,-N));
        }
        return ans(x,n);
    }
int main(){
    double x;
    cout<<"Enter the base: ";
    cin>>x;
    double n;
    cout<<"Enter the power";
    cin>>n;
    cout<<myPow(x,n);
    return 0;
}