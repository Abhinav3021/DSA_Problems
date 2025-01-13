#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), v(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        int c = 0, index = -1;
        string res = "YES";
        for (int i = 0; i < n; i++) {
            v[i] = a[i] - b[i];
            if (v[i] < 0) {
                c++;
                index = i;
            }
        }
        if (c > 1) {
            res = "NO";
        } else if (c == 1) {
            int a = abs(v[index]);
            sort(v.begin(), v.end());
            for (int i = 1; i < n; i++) {
                if (v[i] < a) {
                    res = "NO";
                    break;
                }
            }
        }
        cout << res << endl;
    }
    
}