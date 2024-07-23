#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        vector <int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++){
        if(arr[i]==1){
                v.push_back(i);
            }
        }
        int oper=0;
        if(v.size()==1 || v.size()==n){
            oper=0;
        }
        else{
        for (int i = 0; i < v.size()-1; i++)
        {
            if(v[i+1]-v[i] >1){
                oper+=(v[i+1]-v[i]-1);
            }
            
        }
        }
        cout << oper << endl;
       
        
    }
    
}