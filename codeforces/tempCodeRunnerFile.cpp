#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n;
        cin >> k;
        long long a[n];
        long long x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        unordered_map <int,long long> m;
        for (int i = 0; i < n; i++)
        {
            m[abs(x[i])]+=a[i];
        }
        int remain_bullets=k*(m[x[0]]-1);
        int remain_healths=0;
        string c;
        int q=0;
        for(auto pr : m){
            q++;
            int bullits=(k+remain_bullets);
            if(pr.second+remain_healths > bullits){
                if(pr.first==0){
                    c="NO";
                    q=0;
                    break;
                }
                else{
                    remain_healths+=(pr.second-bullits);

                }
            }
            else{
                remain_bullets+=(bullits-pr.second);

            }
            pr.first=pr.first-1;
        }
        if(q==0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
        
    }
    
}