#include<bits/stdc++.h>
using namespace std;

string reverse_str(string s){
    string a="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'){
            a+='.';
        }
        else{
            a+='#';
        }
    }
    return a;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string initial=".";
        string s="";
        for (int i = 0; i < 2*n; i+=2){
            if(initial=="."){
                    s+="##";
                    initial="#";
                }
                else{
                    s+="..";
                    initial=".";
                }
        }
        int c=0;
        string p=reverse_str(s);
        for (int i = 0; i < 2*n; i+=2){
            if(c==0){
                cout << s << endl;
                cout << s << endl;
                c=1;

            }
            else{
                cout << p << endl;
                cout << p << endl;
                c=0;
            }
        }
        
            
        


    }
}