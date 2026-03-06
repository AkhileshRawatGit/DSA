#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 void subsequences(vector<int>&nums,vector<vector<int>>&ans,vector<int>&dummy,int ind,int target){
        if(ind==nums.size()){
            // if(dummy.size()>0){
            //     int mini=*min_element(dummy.begin(),dummy.end());
            //     int maxi=*max_element(dummy.begin(),dummy.end());
                //if(mini+maxi<=target){
                    ans.push_back(dummy);
                //}
                
            //}
            return;
        }
        dummy.push_back(nums[ind]);
        subsequences(nums,ans,dummy,ind+1,target);
        dummy.pop_back();
        subsequences(nums,ans,dummy,ind+1,target);
    }
int main(){
    vector<int>nums={1,2,3,4};
    vector<vector<int>>ans;
    vector<int>dummy;
    subsequences(nums,ans,dummy,0,4);
    for(auto s:ans){
        for(auto i:s){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}