#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k ;
        int i=0;
        int count=0;
        while (k>0)
        {
            if(i==0){k-=(n-i);
            count++;}
            else{
            k-=(n-i);
            count++;
            if(k>0){k-=(n-i);
            count++;}
            else{break;}
        }
        i++;
        }
        cout << count << endl;
        
    }
    
}