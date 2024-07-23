#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n;
        
        if(n <= 28){
            s.push_back('a');
            s.push_back('a');
            s.push_back('a' + (n - 3));

        }
        else if(n>28 && n <= 53){
            
            s.push_back('a');
            s.push_back('a' + (n - 2-26) );
            s.push_back('z');
        }
        else{
            s.push_back('a' + (n - 1-52) );
            s.push_back('z');
            s.push_back('z');
        }

        cout << s << endl;
    }
    
}
