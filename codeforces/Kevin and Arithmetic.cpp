#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,s=0;
        cin >> n;
        int points=0,even=0,odd=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i]%2==0){even++;}
            else{odd++;}
        }
        if(even>0){points++;}
        if(odd>0 && even==0){points+=odd-1;}
        if(odd>0 && even>0){points+=odd;}
        cout << points << endl;
    }
    
}