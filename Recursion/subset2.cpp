#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void subset(vector<int>& arr, set<vector<int>>& ans, vector<int>& dummy,
                int ind) {
        if (ind >= arr.size()) {
            ans.insert(dummy);
            return;
        }
        dummy.push_back(arr[ind]);
        subset(arr, ans, dummy, ind + 1);
        dummy.pop_back();
        subset(arr, ans, dummy, ind + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        vector<int> dummy;
        subset(arr, ans, dummy, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
int main(){
    vector<int>nums={1,1,3};
    vector<vector<int>>res=subsetsWithDup(nums);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}