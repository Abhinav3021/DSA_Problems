#include<bits/stdc++.h>
using namespace std

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==1){
            for(int i=0;i<n;i++){
            cout << "a";
            }
            cout << "\n";
        }
        else{
            
            string x="a";
            for(int i=0;i<k;i++){
                x+=(x+1+i);
            }
            if(k>=n){
            cout << x+x << endl;

        }
        else{
            for(int i=0;i<(n/k);i++){
                x+=x;
            }
            cout << x << endl;

        }
    }
}