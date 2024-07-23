#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--){
        int x,y;
        cin >> x >> y;
        int screen=0;
        if(y==0){
            if(x%15==0){screen=x/15;}
            else{
            screen=x/15+1;
        }}
        else{
            if(y%2==0){screen+=(y/2);}
            else{
            screen+=(y/2)+1;
        }
        while((screen*15-4*y)<x){
            screen++;
        }
        }
        cout << screen << endl;
    }
    }