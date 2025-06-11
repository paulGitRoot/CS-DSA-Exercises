#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class graph{
    int adj[6][6];
    public:
    graph(){
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                adj[i][j]=0;
            }
        }
    }
    void addEdge(int u,int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void BFS(int start){
        bool visited[6]={false};
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(int i=0;i<6;i++){
                if(adj[node][i]==1&&!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            } 
        }
    }
    void DFS(int start){
        bool visited[6]={false};
        stack<int> s;
        s.push(start);
        visited[start];
        while(!s.empty()){
            int node=s.top();
            s.pop();
            cout<<node<<" ";
            for(int i=5;i>=0;i--){
                if(adj[node][i]==1&&!visited[i]){
                    visited[i]=true;
                    s.push(i);
                }
            }
        }
    }
};
int main(){
    return 0;
}