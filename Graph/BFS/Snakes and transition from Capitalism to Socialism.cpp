#include<bits/stdc++.h>
using namespace std ;
const int N=1e3+10;
const int INF=1e9+10;
int vis[N][N];
int lvl[N][N];
int val[N][N];
int n,m;

void restore(){
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            val[i][j]=0;
            lvl[i][j]=INF;
        }
    }
}

vector<pair<int,int>>movements={
    {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}
};
bool isvalid(int i,int j){
    if(i>=0 && j >=0 && i<n && j<m){return true;}
    return false;
}
int bfs(){
    int mx=0;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx=max(mx,val[i][j]);
        }
    }
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(val[i][j]==mx){
                q.push({i,j});
                vis[i][j]=1;
                lvl[i][j]=0;}}}
    while(!q.empty()){
        auto cur_v=q.front();
        int v_x=cur_v.first;
        int v_y=cur_v.second;
        q.pop();
        for(auto movement: movements ){
            int child_x=movement.first + v_x;
            int child_y=movement.second  +v_y;
            if(!isvalid(child_x,child_y)){ continue;}
            if(vis[child_x][child_y]){continue;}
            q.push({child_x,child_y});
            lvl[child_x][child_y]=lvl[v_x][v_y]+1;
            vis[child_x][child_y]=1;
            ans=max(ans,lvl[child_x][child_y]);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        restore();
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        
        for(int i=0;i<n;i++){
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
            
        }
        int result=bfs();
        cout <<  result << endl;
    }

}