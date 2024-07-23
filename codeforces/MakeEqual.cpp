#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c=0;
        long long arr[n];
        long long sum=0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum+=arr[i];

        }
        long long a=(sum / n);
        if(n==1){
            c=n;

        }
        else{
        long long remain=0;
        for(int i=0;i<n;i++){
            if((arr[i]-a)>0){
                remain+=(arr[i]-a);
            }
            else{
                
            }
            if(arr[i] < a && remain < (a-arr[i]) ){
                c=0;
            }
            else if(arr[i] < a && remain >= (a-arr[i])){
                c++;
                remain=remain - (a-arr[i]);
            }
            else{
                c++;
            }

        }
        }
        if(c==n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        

    }
    
}