#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int count = 0;
        for (int i = 1; i < n; i++) {
            while (v[i] < v[i - 1]) {
                if (v[i] == 0) {
                    count = -1;
                    break;
                }
                v[i] = v[i] * v[i];
                count++;
                if (v[i] > LLONG_MAX) { // Prevent overflow issues
                    count = -1;
                    break;
                }
            }
            if (count == -1) {
                break;
            }
        }
        cout << count << endl;
    }
    return 0;
}
