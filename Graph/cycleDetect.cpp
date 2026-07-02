#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<vector<int>>adj,vector<bool>visited,int node,int parentNode){
    visited[node]=1;

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parentNode) continue;
        if(adj[node][i]!=parentNode && visited[adj[node][i]]==1) return true;
         if(dfs(adj,visited,adj[node][i],node)) return true;
    }
    return false;
}
int main(){
    vector<vector<int>>adj={{1},{0,2,4},{1,3},{2,4},{3,1}};

    vector<bool>visited(adj.size(),0);
    bool flag=false;
    for(int i=0;i<5;i++){
        if(!visited[i] && dfs(adj,visited,i,-1)){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"Found";
    else cout<<"Not found";
}