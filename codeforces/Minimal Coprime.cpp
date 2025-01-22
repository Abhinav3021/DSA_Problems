#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    
    int t;
    cin >> t;
    while (t--) {
        ll l, r,c;
        cin >> l >> r;
        if(l==r){if(l==1){c=1;}else{c=0;}}
        else{c=r-l;}
        cout << c << "\n";
    }
    
    
}