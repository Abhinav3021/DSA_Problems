#include <bits/stdc++.h>
using namespace std;

bool canMakeNonDecreasing(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool possible = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int diff = a[i + 1];
                a[i] -= diff;
                a[i + 1] -= diff;

                // Create a temporary vector slice for validation
                vector<int> temp(a.begin() + max(0, i - 1), a.begin() + min(n, i + 2));
                if (!canMakeNonDecreasing(temp)) {
                    a[i] += diff;
                    a[i + 1] += diff;

                    diff = a[i - 1];
                    a[i] -= diff;
                    a[i - 1] = 0;

                    temp = vector<int>(a.begin() + max(0, i - 1), a.begin() + min(n, i + 2));
                    if (!canMakeNonDecreasing(temp)) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        
        if (possible && canMakeNonDecreasing(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
