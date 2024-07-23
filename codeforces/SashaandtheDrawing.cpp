#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n ,m,c;
        cin >> n >> m;
        if(m==((4*n)-2)){
            c=2*n;

        }
        else{
            if(m%2==0){
                c=m/2;
            }
            else{
            c=(m/2) +1;
            }
        }
        cout << c << endl;




    }
    }