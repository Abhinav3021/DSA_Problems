#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        
        int res = 0;
        
        // Check all possible values of a3
        int a3 = a4 - a2; // a3 = a4 - a2
        if (a3 == a2 + a1) res++;
        if (a4 == a2 + a3) res++;
        if (a5 == a3 + a4) res++;
        
        int max_res = res;
        
        // Check other possible values of a3
        a3 = a5 - a4; // a3 = a5 - a4
        res = 0;
        if (a3 == a2 + a1) res++;
        if (a4 == a2 + a3) res++;
        if (a5 == a3 + a4) res++;
        
        max_res = max(max_res, res);
        
        cout << max_res << endl;
    }
    return 0;
}