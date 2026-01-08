#include<iostream>
#include<vector>
using namespace std;
void subset(vector<int>&nums,vector<vector<int>>&ans,int ind,vector<int>&sum){
    if(ind==nums.size()){
        ans.push_back(sum);
        return;
    }
    sum.push_back(nums[ind]);
    subset(nums,ans,ind+1,sum);
    sum.pop_back();
    subset(nums,ans,ind+1,sum);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>sum;
    subset(nums,ans,0,sum);
    return ans;
}
int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>>res=subsets(nums);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}