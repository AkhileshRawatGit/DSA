#include<iostream>
#include<vector>
using namespace std;

int pickElement(vector<int>ans,int s){
    int low=0;
    int high=s-1;
    while(low<high) {
        int mid=low+(high-low)/2;
        if (ans[mid] < ans[mid+1])
           low = mid+1;
        else
           high = mid;
    }
    return ans[low];
}
int main(){
    
    vector<int>ans={1,7,2,3,4,5,1,2};
    cout<<pickElement(ans,ans.size());
}