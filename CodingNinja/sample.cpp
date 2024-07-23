#include <bits/stdc++.h>
using namespace std;
const long long n=1e6+3;
int primeFact(int a){
	vector <int> v;
	for(int i=2;i*i< a ;i++){
		while(a%i==0){
			v.push_back(i);
			a/=i;
		}
	}
	if(a>1){
		v.push_back(a);
	}
	int sum=0;
	for(int prime :v){
		cout << prime << endl;
		
	}
	return sum;
}
int binaryMulti(long long a, long long b){
    int ans=0;
    while(b>0){
        if(b&1){
            ans=(ans+a)%n;
        }
        a=(a+a)% n;
        b >>=1;
    }
    return ans;
}
int binaryExpan(long long a, long long b){
    int ans=1;
    while(b>0){
        if(b&1){
            ans=binaryMulti(ans,a);
        }
        a=binaryMulti(a,a);
        b >>=1;
    }
    return ans;
}
int main() {
	primeFact(82);
}
