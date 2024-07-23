#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int j=0,b=0;
        vector <int> v;
        for(int i=1;i<n-1;i++){
            if(b==1){
                j=i;
                b=0;
            }
            if(arr[i]==arr[i+1]){
                
                j++;
            }
            else{
            b=1;
            v.push_back(j+1);
            }
        }
        for(int i=0;i<v.size();i++){
            cout << v[i] << " - " <<  endl;
        }
        int s=v.size();
        if(s==0){
            cout << 0 << endl;
        }
        else{
            cout << (v[s-1]-v[0]+1) << endl;
        }
    }
    
}
