#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string newstring;
        set <char> set_s(s.begin(),s.end());
        vector <char> v(set_s.begin(),set_s.end());
        sort(v.begin(),v.end());
        vector <char> vector_v(v);
        reverse(vector_v.begin(),vector_v.end());
        map<char,char> count;
        for(int i=0;i<set_s.size();i++){
             count[v[i]]=vector_v[i];
        }
        for(auto q:s){
            newstring+=count[q];
        }
        cout << newstring << endl;



    }
}