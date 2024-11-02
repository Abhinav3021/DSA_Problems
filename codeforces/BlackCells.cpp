#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, result = __LONG_LONG_MAX__;  // Changed to long long max since we're using long long
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        if(n == 1) {
            result = 1;
        } 
        else {
            for(int i = 1; i < n; i++) {
                if(v[i] < v[i-1]) {  // If current element is less than previous
                    result = 0;  // No moves needed as array is not sorted
                    break;
                }
                result = min(result, (long long)(v[i] - v[i-1]));
            }
            
            // If array is sorted, result + 1 will be the answer
            // Because we can make that many moves before array becomes unsorted
            if(result != 0) {
                result = (result / 2) + 1;
            }
        }
        cout << result << endl;
    }
    return 0;
}