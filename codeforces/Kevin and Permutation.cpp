#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        int j=1,p=n;
        for(int i=0;i<n;i++){
            if((i+1)%k==0){
                v[i]=j;
                j++;
            }
            else{v[i]=p; p--;}
        }
        for(auto i:v){
            cout << i << " ";
        }
        cout <<"\n";
    }
}