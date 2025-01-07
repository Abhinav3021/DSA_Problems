#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n,res=0,a=0;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){cin >> v[i];}
        for(int i=0;i<n-1;i++){
            if((v[i]<2*v[i+1]) && (v[i+1]<2*v[i]) && (v[i]+v[i+1]>v[i]) && (v[i]+v[i+1]>v[i+1])){
                res=1;
                a++;
                break;
            }
        }
        for(int i=0;i<n-2;i++){
            if((v[i]+v[i+1]>v[i+2]) && (v[i]+v[i+2]>v[i+1]) && (v[i+2]+v[i+1]>v[i])){
                res=1;
                a++;
                break;
            }
        }
        
        if(res==1){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
}