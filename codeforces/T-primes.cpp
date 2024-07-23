#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long ar[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    for(int i=0;i<n;i++){
        int c=0;
        int j=1;
        while(j<ar[i]){
            if(ar[i]%j==0){
                c++;
            }
            j++;
        }
        if(c==2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}