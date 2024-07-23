#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    int s=a[0];
	    for(int i=1;i<n;i++){
	        s=s ^ a[i];
	    }
	    int c=s;
	    for(int i=0;i<n;i++){
	        int temp=s^a[i];
	        if(c>temp){
	            c=temp;
	        }
	        
	    }
	    
	    cout << c << endl;
	    
	}
	
	return 0;
}
