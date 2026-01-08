#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void combination(vector<int>&ARR,vector<vector<int>>&ans,vector<int>&dummy,int n,int ind){
    
    if(ind==ARR.size()||n<0){
        if(n==0){
        ans.push_back(dummy);
    }
    return;
    }
    dummy.push_back(ARR[ind]);
    combination(ARR,ans,dummy,n-ARR[ind],ind);
    dummy.pop_back();
    combination(ARR,ans,dummy,n,ind+1);
}
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    sort(ARR.begin(),ARR.end());
    vector<vector<int>>ans;
    vector<int>dummy;
    combination(ARR,ans,dummy,B,0);
    return ans;
}
int main(){
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    vector<int>ans={1,2,3,4,5,6,7};
    vector<vector<int>>res=combSum(ans,target);
    for(auto s:res){
        for(auto i:s){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}