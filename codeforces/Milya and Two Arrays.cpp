#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        string res;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0;i<n;i++){m1[a[i]]++;}
        for(int i=0;i<n;i++){m2[b[i]]++;}
        if(m1.size()>=2){
            if(m2.size()>=2){res="YES";}
            else{if(m1.size()>=3){res="YES";}
            else{res="NO";}}
        }
        else{
            if(m2.size()>2){res="YES";}
            else{res="NO";}
        }
        cout << res << endl;

    }
    
}
