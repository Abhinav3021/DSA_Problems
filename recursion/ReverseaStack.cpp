#include<bits/stdc++.h>
using namespace std ;
class Solution{
public:
    void InsertReverse(stack<int> &St,int x){
        if(St.empty()){
            St.push(x);
            return;
        }
        int temp=St.top();
        St.pop();
        InsertReverse(St,x);
        St.push(temp);
        
    }
    void Reverse(stack<int> &St){
        if(!St.empty()){
            int x=St.top();
            St.pop();
            Reverse(St);
            InsertReverse(St,x);
        }
    }
};