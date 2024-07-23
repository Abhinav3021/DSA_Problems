#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <int> v;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      v.push_back(a);
    }
    int c=0;
    if(n==1 ){
      c=0;
    }
    else if(n==2){
      if((v[0]+v[1])%2==0){
        c=0;
      }
      else{
        c=1;
      }
    }
    else{
    for(int i=0;i<v.size()-1;i++){
      if((v[i+1]+v[i])%2!=0 ){
        if((v[i+2]+v[i])%2==0){
          c++;
          v.erase(v.begin()+i+1);
        }
        
      }
      
    }
    }
    cout << c << endl;

    return 0;

  }