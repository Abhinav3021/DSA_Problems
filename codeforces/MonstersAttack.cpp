#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long a[n], x[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        
        unordered_map<int, long long> m;
        for (int i = 0; i < n; i++)
            m[abs(x[i])] += a[i];
        
        long long remain_bullets = k * (m[x[0]] - 1);
        long long remain_healths = 0;
        bool possible = true;
        
        for (auto &pr : m) {
            long long bullets = k + remain_bullets;
            if (pr.second + remain_healths > bullets) {
                if (pr.first == 0) {
                    possible = false;
                    break;
                } else {
                    remain_healths += (pr.second - bullets);
                }
            } else {
                remain_bullets += (bullets - pr.second);
            }
        }
        
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
