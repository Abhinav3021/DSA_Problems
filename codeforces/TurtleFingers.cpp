#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,k=0,x=0,y=0;
        long long l;
        cin >> a;
        cin >> b;
        cin >> l;
        int i=0,j=0;
        while(l>=pow(a,x)*pow(b,y)){
            long long  p=pow(a,x+1)*pow(b,y);
            long long q=pow(a,x)*pow(b,y+1);
            if(l>=pow(a,x+1)*pow(b,y) && l% p==0){
                x++;
                
            }
            if(l>=pow(a,x)*pow(b,y+1) && l%q==0){
                y++;
                
            }
            else{
                break;
            }
        }
        while(l>=pow(a,i)){
            int q=(pow(a,i));
            if(l% q==0){
            i++;
            }
            else{
                break;
            }
        
        }
        while(l>=pow(b,j))
        {
            int p=pow(b,j);
            if(l % p ==0){
            j++;
            }
            else{
                break;
            }
        }
        i--;
        j--;
       
        
        
        k+=(x+1)*(y+1)+(i+j-x-y);
        cout << k << endl;






    }
}