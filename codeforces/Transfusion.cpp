#include <iostream>
#include <vector>
#include <string>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        long long sum=0;
        string res="YES";
        for(int i=0;i<n;i++){cin >> v[i]; sum+=v[i];}
        if(sum%n!=0){res="NO";}
        else{
            int a=sum/n;
            for(int i=0;i<n-2;i++){
                if(v[i]<a){v[i+2]-=a-v[i]; v[i]=a;}
                else if(v[i]==a){continue;}
                else if(v[i]>a){v[i+2]+=v[i]-a; v[i]=a;}
            }
            for(int i=0;i<n;i++){
                if(v[i]!=a){res="NO"; break;}
            }
        }
        cout << res << endl;

    }
    
}