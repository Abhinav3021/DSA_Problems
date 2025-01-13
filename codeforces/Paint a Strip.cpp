#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;  cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int sum=1,one=1;
        if(n<=2){one=n;}
        else{
            int i=1;
            while (i<n)
            {
                i=2*(i+1);
                one++;
            }
            
        }
        cout << one << endl;
    }
    
}