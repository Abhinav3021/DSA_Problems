/*
There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), the i-th directed edge goes from Vertex xi to yi. G does not contain directed cycles.
Find the length of the longest directed path in G. Here, the length of a directed path is the number of edges in it.
*/

#include<bits/stdc++.h>
using namespace std ;
const int N=100010;
vector <int> g[N];
bool visited[N];
stack<int> topoOrder;
int dp[N];
void dfs(int node){
    visited[node]=true;
    for(auto child: g[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
    topoOrder.push(node);    //A DFS function that visits all nodes reachable from node and pushes the node onto topoOrder stack after all its descendants have been visited (post-order).
}

int func(int node){
    if(g[node].size()==0){return 0;}
    if(dp[node]!=-1){
        return dp[node];
    }
    visited[node]=1;
    int ans=0;
    for(auto child:g[node]){
        if(!visited[N]){
        ans=max(ans,func(child)+1);
    }
    }
    return dp[node]=ans;

}

int main(){
    int n,m;
    cin >> n >> m;
    memset(dp,-1,sizeof(dp));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <=n; i++)
    {
        if(!visited[i]){dfs(i);}
    }
    
    int result=0;
    while(!topoOrder.empty()){           //Topological Sorting: Nodes are processed in topological order to ensure that all nodes in a subpath are processed before the path's starting node
        int node=topoOrder.top();
        topoOrder.pop();
        result=max(result,func(node));
    }
    cout << result << endl;
}