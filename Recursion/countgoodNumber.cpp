#include<iostream>
using namespace std;
 static const long long MOD = 1000000007;
    long long pow1(long long base,long long power){
        long long ans=1;
        while(power>0){
            if(power%2==1){
                ans=(ans*base)%MOD;
                power=power-1;
            }
            else{
                power=power/2;
                base=(base*base)%MOD;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evenpos=(n+1)/2;
        long long oddpos=n/2;
        long long ans=(pow1(5,evenpos)*pow1(4, oddpos))%MOD;
        return (int)ans;
    }
int main(){
    
    long long n;
    cout<<"Enter the number";
    cin>>n;
    cout<<countGoodNumbers(n);
    return 0;
}