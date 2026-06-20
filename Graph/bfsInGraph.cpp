#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){

    vector<vector<int>>Adj={{1,2},{0,5,7},{0,3,4},{2},{2},{1,6},{5,8},{1,8},{6,7}};
    queue<int>q;
    vector<bool>visited(9,0);
    vector<int>ans;
    q.push(0);
    visited[0]=1;
    while(q.size()>0){
        int a=q.front();
        q.pop();
        ans.push_back(a);
        for(int i=0;i<Adj[a].size();i++){
            if(visited[Adj[a][i]]==0){
                q.push(Adj[a][i]);
                visited[Adj[a][i]]=1;
            }
        }
        
    }
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    return 0;
}