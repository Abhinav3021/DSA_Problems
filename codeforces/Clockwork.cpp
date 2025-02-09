#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        string res = "YES";
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] <= 2 * max(i, n - 1 - i)) {
                res = "NO";
            }
        }
        cout << res << endl;
    }
    return 0;
}