#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector <vector<int>> subset;
    void solve (vector <int> &v,int i,vector<int> &a){
        if(i==v.size()){
            subset.push_back(a);
            return;
        }
        solve(v,i+1,a);
        
        a.push_back(v[i]);
        solve(v,i+1,a);
        a.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> empty;
        solve(nums,0,empty);
        return subset;
    }
};