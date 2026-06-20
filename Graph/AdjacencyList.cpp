#include<iostream>
#include<vector>
using namespace std;

int main(){
    int vertex,edges;
    cout<<"Enter the vertexs: ";
    cin>>vertex;
    cout<<"Enter the edges: ";
    cin>>edges;
    vector<vector<int>>Adj(vertex);
    int s,d;
    for(int i=0;i<edges;i++){
        cin>>s>>d;
        Adj[s].push_back(d);
        Adj[d].push_back(s);
    }

    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j=0;j<Adj[i].size();j++){
            cout<<Adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}