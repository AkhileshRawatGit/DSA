#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bfs(int vertex,vector<vector<int>>&adj,vector<bool>&visited){
    queue<pair<int,int>>q;
    q.push({vertex,-1});
    visited[vertex]=1;
    while(q.size()>0){
        int node=q.front().first;
        int parentNode=q.front().second;
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            //equal to parent
            if(adj[node][i]==parentNode) continue;
            if(visited[adj[node][i]]==1){
                return 1;
            }
            q.push({adj[node][i],node});
            visited[adj[node][i]]=1;
        }
    }
    return 0;
}
int main(){
    vector<vector<int>>adj={{1},{0,2},{1,3},{2,4},{3}};
    vector<bool>visited(adj.size(),0);
    bool flag=false;
    for(int i=0;i<5;i++){
        if(!visited[i] && bfs(i,adj,visited)){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"Found"<<" ";
    else cout<<"Not found";
    return 0;
}