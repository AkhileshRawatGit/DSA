#include<iostream>
#include<vector>
using namespace std;
int main(){

    int vertex,edges;
    cout<<"Enter the vertexs: ";
    cin>>vertex;
    cout<<"Enter the edges: ";  //in graph the edges are always vertex-1
    cin>>edges;

    vector<vector<bool>>Adj(vertex,vector<bool>(vertex,0));
    int s,d; //source vertex and destination vertex
    for(int i=0;i<edges;i++){
        cin>>s>>d;
        Adj[s][d]=1;
        Adj[d][s]=1;
    }

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<Adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}