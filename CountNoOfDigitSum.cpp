// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long Digitsum(long long sum,int index, bool tight,vector<int>&nums){
    if(sum==0) return 1;
    if(sum<0 ||index==nums.size()) return 0;
    
    long long result=0;
    if(tight){
        for(int i=0;i<nums[index];i++){
            result+=Digitsum(sum-i,index+1,0,nums);
        }
        result+=Digitsum(sum-nums[index],index+1,1,nums);
    }
    else{
        for(int i=0;i<=9;i++){
            result+=Digitsum(sum-i,index+1,0,nums);
        }
    }
    return result;
}
long long countDigit(long long n,long long s){
    vector<int>nums;
    while(n>0){
        nums.push_back(n%10);
        n/=10;
    }
    reverse(nums.begin(),nums.end());
    return Digitsum(s,0,1,nums);
}


int main() {
    // Write C++ code here
    cout << "Start small. Ship something.";
    long long n;
    cout<<"enter a number: "<<" ";
    cin>>n;
    long long sum;
    
    cout<<"enter a of sum: "<<" ";
    cin>>sum;
    
    cout<<countDigit(n,sum);
    
    return 0;
}