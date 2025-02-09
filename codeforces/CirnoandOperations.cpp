#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t;
    cin >> t; 
    while (t--)
    {
        long long n,res=0,sum=0,flag=0; cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){cin >> v[i]; sum+=v[i]; }
        if(n==1){res=v[0];}
        else{
             for(int i=0;i<n;i++){
                vector<int> v_curr=v;
                for(int st=0;st<i;st++){
                    if(v_curr[0]>v_curr.back()){
                        reverse(v_curr.begin(),v_curr.end());
                    }
                    vector<int> diff;
                    for(int k=0;k<v_curr.size();k++){
                        diff.push_back(v_curr[i+1]-v_curr[i]);
                    }
                    v_curr=diff;
                }
                long long s=0;
                for(int a:v_curr){s+=a;}
                res=max(s,sum);
             }

        }
        
        cout << res << endl;
    }
    
}