#include<bits/stdc++.h>
using namespace std;
int binaryno(int n){
    string s=to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]!='1' || s[i]!='0'){
            return 0;
        }
        
    }
    return 1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s=to_string(n);
        int m=s.size();
        if(binaryno(n)){
            cout << "YES" << endl;
        }
        vector <int> pf;
        for (int i = 2; i*i <= n; i++)
        {
            while(n%i==0){
                pf.push_back(i);
                n/=i;
            }
        }
        if(n>1){
            pf.push_back(n);
        }
        int c=0;
        for (int prime : pf){
            if(prime!=2 || prime!=5){
                if(!binaryno(prime)){
                    cout << "NO" << endl;
                    c=1;
                    break;
                    
                }
            }
        }
        if(c==0){
            cout << "YES" << endl;
        }

    }
}