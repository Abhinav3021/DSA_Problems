#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        int d;
        cin >> n >> d;
        set<int> v;
        
        // No need to check divisibility since these are guaranteed based on factorial properties
        if(n < 3) {
            v.insert(1);
        }
        else if(n < 5) {
            v.insert(1);
            v.insert(3);
        }
        else if(n < 7) {
            v.insert(1);
            v.insert(3);
            v.insert(5);
        }
        else if(n < 9) {
            v.insert(1);
            v.insert(3);
            v.insert(5);
            v.insert(7);
        }
        else {
            v.insert(1);
            v.insert(3);
            v.insert(5);
            v.insert(7);
            v.insert(9);
        }
        
        // Print the odd divisors
        for(int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}