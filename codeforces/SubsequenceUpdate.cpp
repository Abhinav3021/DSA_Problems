#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int n, int l, int r, vector<ll>& arr) {
    // If segment length is 1, return the element itself
    if(l == r) return arr[l-1];
    
    // Store elements that are outside the range [l,r]
    vector<ll> outside_elements;
    for(int i = 0; i < l-1; i++) {
        outside_elements.push_back(arr[i]);
    }
    for(int i = r; i < n; i++) {
        outside_elements.push_back(arr[i]);
    }
    
    // Store elements in the range [l,r]
    vector<ll> range_elements;
    for(int i = l-1; i < r; i++) {
        range_elements.push_back(arr[i]);
    }
    
    // Sort both arrays to optimize swapping
    sort(outside_elements.begin(), outside_elements.end());
    sort(range_elements.begin(), range_elements.end());
    
    ll current_sum = 0;
    for(int i = 0; i < r-l+1; i++) {
        current_sum += range_elements[i];
    }
    
    // Try swapping maximum elements in range with minimum elements outside
    ll min_sum = current_sum;
    for(int i = 0; i < min((int)outside_elements.size(), r-l+1); i++) {
        // We can swap the largest element in range with smallest element outside
        if(outside_elements[i] < range_elements[r-l-i]) {
            current_sum = current_sum - range_elements[r-l-i] + outside_elements[i];
            min_sum = min(min_sum, current_sum);
        }
    }
    
    return min_sum;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << solve(n, l, r, arr) << "\n";
    }
    
    
}