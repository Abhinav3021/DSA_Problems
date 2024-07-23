#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k==0){
	    map <string,int> maps;
	    for(int i=0;i<n;i++){
	        if(i%k==0){
	            maps[s.substr(i,k)]+=1;
	        }
	    }
	    if(maps.size()>2){
	        return 0;
	    }
	    else if(maps.size()==1){
	        return 1;
	    }
	    else{
	        for(auto pr: maps){
	            if((pr.second >1 && ++pr.second<2) || (pr.second<2 && ++pr.second >1)){
	                return 1;
	            }
	        }
	        
	    
	    }
	    }
	    return 0;
	}
	
};