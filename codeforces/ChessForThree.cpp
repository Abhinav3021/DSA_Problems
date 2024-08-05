#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int maxdraw=0;
        int sum=(a+b+c)/2;
        if(a==0 && b==0 && c==0){maxdraw=0;}
        else if(a==0 && b==0 && c!=0){
            maxdraw=0;
        }
        else if(a==0 && b!=0 && c!=0){
            maxdraw=b;
        }
        else if(a==b && b==c){
            maxdraw=-1;
        }
        else if(a==1 && b==1 && c>1){
            maxdraw=2;
        }
        else if(a==1 && b>1 && c>1){
            maxdraw=b;
        }
        else{
            maxdraw=sum;
        }
        cout << maxdraw << endl;
    }
}