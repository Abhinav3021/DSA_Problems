#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t; cin >> t;
    while (t--)
    {
       int n,k;
       cin >> n >> k;
       vector<int> v(n);
       for(int i=0;i<n;i++){cin >> v[i];}
       int res=-1;
       if(k==n){
        int j=1;
        for(int i=1;i<n;i=i+2){
        if(v[i]!=j){res=j; break;}
        j++;
       }
       if(res==-1){
        res=k/2 +1;
        
       } 
       }
       else{
        for(int i=1;i<=n-k+1;i++){
            if(v[i]!=1){res=1;break;}
        }
        int j;
        if(res==-1){
            j=2;
            for(int i=n-k+1;i<n;i=i+2){
                if(v[i]!=j){res=j;break;}
            }
        }
        }
       cout << res << endl; 
       }


       
    }
    
