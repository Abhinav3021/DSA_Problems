#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    s.append(" ");
	    cin >> s;
	    int x=0,y=0;
	    for(int i=0;i<n;i++){
	        if((s[i]=='L' ||s[i]=='R') && (s[i+1]!='L' || s[i+1]!='R')){
	            if(s[i]=='L'){
	                x--;
	            }
	            else{
	                x++;
	            }
	        }
	        if((s[i]=='U' ||s[i]=='D') && (s[i+1]!='U' || s[i+1]!='D')){
	            if(s[i]=='D'){
	                y--;
	            }
	            else{
	                y++;
	            }
	        }
	        
	        
	    }
	    cout << x << y << endl;
	}
	return 0;
}
