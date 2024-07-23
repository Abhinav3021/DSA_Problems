/*This kanpsack problem is same but the constsaints are different
1≤N≤100
1≤W≤10^9
1≤wi≤W
1≤vi≤10^3
as the normal kanpsack TC:-O(N*W) but in this case we have TC=10^11
so we have to first calculate all the max val then we find the minimum weight requies to all val(1 t0 max val)
then print the val who's weight < W
*/

#include<bits/stdc++.h>
using namespace std ;
const int INF=1e15;
int val[100];
long long wt[100];
int dp[110][100010];

long long func(int index,int val_left){
    if(val_left==0){return 0;}
    if(index<0){return INF;}
    if(dp[index][val_left]!=-1){ return dp[index][val_left];
    } //returing very large value because of the the given value is not achived by it and it will be rejected in func(n-1,i)<=w
    //don't choose the value
    long long ans=func(index-1,val_left);
    if(val_left - val[index] >=0){
    //Choose the value
    ans=min(ans,func(index-1,val_left-val[index])+wt[index]);
    }
    return dp[index][val_left]=ans;
}

int main(){
  memset(dp,-1,sizeof(dp));
  int n;
  long long w;
  cin >> n >> w;
  for(int i=0;i<n;i++){
    cin >> wt[i] >> val[i];
  }
  long long sum=0;
  for(int i=0;i<n;i++){
    sum+=val[i];
  }
  int maxval=sum;   // maximun value will be O(N*vi) ---100*1000
  for(int i=maxval;i>=0;--i){
    if(func(n-1,i) <=w){
        cout << i << endl;
        break;
    }
  }
}