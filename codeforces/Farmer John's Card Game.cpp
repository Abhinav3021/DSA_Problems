#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end()); // sort each cow's cards
        }
        
        vector<int> p(n);
        iota(p.begin(), p.end(), 0); // initialize p with 0, 1, ..., n-1
        
        // Sort cows based on their smallest card
        sort(p.begin(), p.end(), [&](int a, int b) {
            return v[a][0] < v[b][0];
        });
        
        bool possible = true;
        int last_card = -1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[p[j]][i] <= last_card) {
                    possible = false;
                    break;
                }
                last_card = v[p[j]][i];
            }
            if (!possible) break;
        }
        
        if (possible) {
            for (int i = 0; i < n; i++) {
                cout << p[i] + 1 << " "; // output 1-based index
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}