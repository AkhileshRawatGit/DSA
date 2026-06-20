#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(vector<vector<int>>&Adj,vector<bool>&visited,vector<int>&ans,int node){
    visited[node]=1;
    ans.push_back(node);
    for(int i=0;i<Adj[node].size();i++){
        if(visited[Adj[node][i]]==0){
            dfs(Adj,visited,ans,Adj[node][i]);
        }
    }
}
int main(){

    vector<vector<int>>Adj={{1,2},{0,5,7},{0,3,4},{2},{2},{1,6},{5,8},{1,8},{6,7}};
    vector<bool>visited(9,0);
    vector<int>ans;
    dfs(Adj,visited,ans,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}