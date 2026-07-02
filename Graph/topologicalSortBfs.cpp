#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>adj={{1,2},{3},{3},{}};
    queue<int>q;
    vector<int>id(adj.size(),0);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            id[adj[i][j]]++;
        }
    }
    for(int i=0;i<adj.size();i++){
        if(!id[i]){
            q.push(i);
        }
    }
    vector<int>ans;
    while(q.size()>0){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int j=0;j<adj[node].size();j++){
            id[adj[node][j]]--;
            if(id[adj[node][j]]==0){
                q.push(adj[node][j]);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
    }
    return 0;
}