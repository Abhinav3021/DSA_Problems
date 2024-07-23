#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <int > v;
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            sum+=a;
            v.push_back(a);
        }
        int i=0;
        while (sum%3!=0)
        {
            
            for(int j=0;j<n;j++){
                if((sum-v[i])%3==0 || (sum+1)%3==0){
                    i++;
                    break;
                }
                else{
                    continue;
                }


            }
        }
        cout << i << endl;
        
        

        


    }

}