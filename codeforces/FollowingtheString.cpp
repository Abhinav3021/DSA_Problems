#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v;
        vector <int> counts(26,0);
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        int initial='a';
        string s;
        for(int i=0;i<n;i++){
            while(counts[initial-'a'] < v[i]){
                s+=initial;
                counts[initial -'a']++;
            }
            initial++;
        }
        cout << s << endl;

    }
}