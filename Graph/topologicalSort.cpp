#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    void topological(vector<vector<int>>&adj, vector<bool>&visited,int node,stack<int>&st){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]]=1;
                topological(adj,visited,adj[node][i],st);
            }
        }
        st.push(node);
        return;
    }
int main(){

    //adjacency list
    vector<vector<int>>adj={{1,2},{3},{3},{0}};
    stack<int>st;
    vector<bool>visited(4,0);
    for(int i=0;i<4;i++){
        if(!visited[i]){
            topological(adj,visited,i,st);
        }
    }
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}