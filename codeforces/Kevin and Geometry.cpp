#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n,res=-1,count=0;
        cin >> n;
        int a=-1,b=-1,c=-1;
        vector<int> v(n);
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            m[v[i]]++;
            if(m[v[i]]>=4){res=1; a=v[i]; b=v[i];c=v[i]; }
            if(m[v[i]]>=2){count++;}
        }
        if(count==0){res=0;}
        if(count>=2 && res==-1){res=1;
        for(auto p:m){if(p.second>=2){if(a==-1 && b==-1){a=p.first;b=p.first;}if(c==-1){c=p.first;}}}
         }
         if(res==-1 && count==1){
            for(auto p:m){if(p.second>=2){c=p.first; p.second=0;}}
            sort(v.begin(),v.end());
            for(int i=0;i<n;i++){
                if(v[n-i-1]-v[i]<2*c && m[v[n-i-1]]==1 && m[v[i]]==1 && v[n-i-1]!=v[i]){
                    a=v[i]; b=v[n-i-1]; res=1; break;
                }
            }
            if(res==-1){res=0;}
            
         }
         if(res==1){
         cout << a << " " << c << " " << b << " " << c << endl;
         }
         else{cout << -1 << endl;}
    }

}