#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t; cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int c=0;
        for(auto i:s){
            if(i=='1'){c++;}
        }
        cout << c << endl;

    }
    
}