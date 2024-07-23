#include<bits/stdc++.h>
using namespace std ;
int dp[100010][5];
vector<int> a,b,c;
int func(int i,int prev){
    if(i==-1){return 0;}
    if(dp[i][prev]!=-1){return dp[i][prev]; }
    int ans=-1;
    if( prev!=1){ ans=max(ans,func(i-1,1)+a[i]);}
    if( prev!=2){ ans=max(ans,func(i-1,2)+b[i]);}
    if(prev!=3){
        ans=max(ans,func(i-1,3)+c[i]);
    }
    return dp[i][prev]=ans;
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i] ;
    }
    int result=func(n-1,0);
    cout << result;
    //return result;
    
}