#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        long long l = (static_cast<long long>(k) * (k + 1)) / 2; // Casting to long long
        int a[n];
        int b[m];
        int c1 = 0, c2 = 0;
        set<int> s1;
        set<int> s2;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] <= k) {
                s1.insert(a[i]);
                c1++;
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            if(b[i] <= k) {
                s2.insert(b[i]); // Fixed the typo: should be s2, not s1
                c2++;
            }
            
        }
        int c3=0;
        for(int i=1;i<=k;i++){
            if(s1.find(i)!=s1.end() || s2.find(i)!=s2.end()){
                c3++;
            }
        }
        
        if(c3==k && s1.size()>=3 && s2.size() >=3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
