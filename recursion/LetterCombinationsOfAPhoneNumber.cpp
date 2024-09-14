/*Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<string> v;
    vector<string> mapping={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void func(string digits,int index,string s){
        if(s.size()==digits.size()){
            v.push_back(s);
            return;
        }
        int d=digits[index]-'0'; //for making it into integer
        string letters=mapping[d];

        for(auto letter:letters){
            s.push_back(letter);
            func(digits,index+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return v;
        func(digits,0,"");
        return v;
    }
};