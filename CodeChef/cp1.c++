#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    int N=1e5 +10;
    int has[N];
    while(t--){
        int n;
        cin >> n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin >> ar[i];
        }
         for(int i=0;i<N;i++){
        has[i]=0;
    }
        for(int i=0;i<n;i++){
            has[ar[i]]++;
        }
        int c=0;
         for(int i=0;i<N;i++){
            if(has[i]>0){
                c++;
            }
        }
        if(c==1){
            cout << "Yes" << endl;
        }
        int a[2];
        int b;
        if(c==2){
            for(int i=0;i<N;i++){
            if(has[i]>0){
                b=has[i];
            }
            }
            for(int i=0;i<2;i++){
                a[i]=b;
            }
            if(a[0]==a[1]){
                cout << "Yes" << endl;
            }
            else if(abs(a[0]-a[1]==1)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        

    }

}
}