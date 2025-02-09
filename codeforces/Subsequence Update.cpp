#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        ll sum = 0;
        for (int i = l - 1; i < r; i++) {
            sum += arr[i];
        }
        cout << sum << endl;
    }
    
 
}