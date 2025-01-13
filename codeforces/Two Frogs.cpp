#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,a,b;
        cin >> n >> a >> b;
        vector<int> v(n+1,0);
        v[a]=1; v[b]=2;  // 1 -Alice 2-bob
        int chance=1,win=0;
        while(win==0){
            if(chance==1){
                if((a==n && b==n-1)|| (a==1 && b==2)){win=2;}
                else{
                    if(b>a && a+1<=n){
                        if(b==a+1 && a-1>=1){a=a-1;}
                        else{a=a+1;}
                    }
                    else{
                        if(b==a-1 && a+1<=n){a=a+1;}
                        else{a=a-1;}
                    }
                    chance=2;
                }
            }
            else{
                if((b==n && a==n-1)|| (b==1 && a==2)){win=1;}
                if(a>b && b+1<=n){
                        if(a==b+1 && b-1>=1){b=b-1;}
                        else{b=b+1;}
                    }
                    else{
                        if(a==b-1 && b+1<=n){b=b+1;}
                        else{b=b-1;}
                    }
                    chance=1;
            }
        }
        if(win==1){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
    
}