#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsack(vector<int>wt,vector<int>val,int W,int n){
    //base condition
    if(n==0|| W==0) return 0;
    if(wt[n-1]<=W){
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
    }
    else{
        return knapsack(wt,val,W,n-1);
    }
}
int main(){
    int n;
    cout<<"enter the weight array: ";
    cin>>n;
    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int m;
    cout<<"enter value array: ";
    cin>>m;
    vector<int>val(m);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int capacity;
    cout<<"enter the capacity: ";
    cin>>capacity;
    cout<<knapsack(wt,val,capacity,n);
    return 0;
}