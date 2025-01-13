#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        int d;
        cin >> n >> d;
        vector<int> v;

        //here we are checking the conditions for every odd numbers 
        v.push_back(1);
         
        if(n>=3 || d%3==0) {
            v.push_back(3);
        }
        if(d%5==0) {
            v.push_back(5);
        }
        if(n>=3 || d%7==0) {     // use this https://www.youtube.com/watch?v=TCbCTb0vdOg
            v.push_back(7);
        }
        if(n>=6 || d%9==0 || (n>=3 && d%3==0)) {
            v.push_back(9);
        }
        
        for(int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
}