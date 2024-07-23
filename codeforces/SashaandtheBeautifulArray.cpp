#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <long long> v;
        for(int i=0;i<n;i++){
            int a;

            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        cout << (v[n-1]-v[0]) << endl ;

    }
    
}