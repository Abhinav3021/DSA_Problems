#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        
        long long count = 0;
        long long result = 0,curr=0;
        int j=0;
        for (int i = n - 1; i >= 0; i--) {
            count += v[i];
            j++;
            if (i > 0 && (v[i - 1] == v[i] || v[i - 1] == v[i] - 1)) {
                if(j==1){curr=v[i];}
                if(curr-v[i-1] >1){count=0;
                j=0;}
                continue;
            } else {
                if (count <= m) {
                    result = max(result, count);
                }
                count = 0;
                j=0;
            }
        }
        
        cout << result << endl;
    }
    
}
