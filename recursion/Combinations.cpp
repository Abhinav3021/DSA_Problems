#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<vector<int >> result;
    void Combinations(int n,int k,int i,int j,vector<int> &v){
        if(j==k){
            result.push_back(v);
            return;
        }
        if(i<=n){
        Combinations(n,k,i+1,j,v);

        v[j]=i;
        Combinations(n,k,i+1,j+1,v);
    }
    } 
    vector<vector<int>> combine(int n, int k) {
        vector <int> empty(k,0);
        Combinations(n,k,1,0,empty);
        return result;
    }
};