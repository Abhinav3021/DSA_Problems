#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> qlist(m);
        unordered_map<int, int> know;
        for (int i = 0; i < m; i++) {
            cin >> qlist[i];
        }
        for (int i = 0; i < k; i++) {
            int temp = 0;
            cin >> temp;
            know[temp]++;
        }
        string res(m, '1'); // Initialize res with size m and default value '1'
        if (k > n - 1) {
            for (int i = 0; i < m; i++) {
                res[i] = '1';
            }
        } else if (k < n - 1) {
            for (int i = 0; i < m; i++) {
                res[i] = '0';
            }
        } else {
            for (int i = 0; i < m; i++) {
                if (know[qlist[i]] == 0) {
                    res[i] = '1';
                } else {
                    res[i] = '0';
                }
            }
        }
        cout << res << endl;
    }
    
}