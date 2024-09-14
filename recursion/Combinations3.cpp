#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> digit={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result;
    void func(int k,int n, int index,vector<int>& v){
        if(n==0 && k==0){
            result.push_back(v);
            return;
        }
        if(k<=0 || n<0 || index>=digit.size() ) return;
        v.push_back(digit[index]);
        func(k-1,n-digit[index],index+1,v);
        v.pop_back();
        func(k,n,index+1,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        func(k,n,0,v);
        return result;
    }
};