#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<string> result;
    void generate(string s,int n,int i,int open,int close ){
        if(open== 0 && close== 0){result.push_back(s);
        return;}
        if(open >0){
            s[i]='(';
            generate(s,n,i+1,open-1,close);
        }
        if(close >0 && open<close){
            s[i]=')';
            generate(s,n,i+1,open,close-1);
    }
    }
    vector<string> generateParenthesis(int n) {
        string s(2*n,0);
        generate(s,n,0,n,n);
        return result;
    }
};