#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                j=i;
                break;
            }
        }
        int k=j;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                k=i;
            }
        }
        cout << ((k-j) +1) << endl;

    }
    return 0;
}