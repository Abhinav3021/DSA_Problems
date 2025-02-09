#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long s1 = 0, s2 = 0, sum;
        vector<int> arr1 = v;
        vector<int> arr2 = v;
        sort(arr1.begin() + l - 1, arr1.begin() + r);
        sort(arr2.begin() + l - 1, arr2.begin() + r, greater<int>());
        for (int i = l - 1; i < r; i++) {
            s1 += arr1[i];
            s2 += arr2[i];
        }
        sum = min(s1, s2);
        cout << sum << endl;
    }

    return 0;
}