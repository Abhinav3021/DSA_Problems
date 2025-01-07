#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long count=1,i=1;
        while(n>3){
            count+=i;
            i*=2;
            n=n/4;
        }
        cout << count << endl;
    }
    
}