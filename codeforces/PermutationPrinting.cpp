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
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        for(int i=1;i<=n-3;i++){
            if(i%2!=0){
            v.insert(v.begin()+i-1,i+3);
            }
            else{
                v.insert(v.begin(),i+3);
            }

        }
        for(auto pr: v){
            cout << pr << " ";
        }
        cout << "\n";

    }
    
}