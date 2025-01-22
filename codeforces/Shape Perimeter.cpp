#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(2));
        int perameter=4*m*n;
        for(int i=0;i<n;i++){
            int t1,t2;
            cin >> t1 >> t2;
            if(i==0){continue;}
            perameter-=2*(m-t1+m-t2);
            }
        
        cout << perameter << endl;
    }
    
}