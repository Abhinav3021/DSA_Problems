#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,k;
        cin >> x >> y >> k;
        int ax=0,ay=0,bx=y,by=0,cx=0,cy=0,dx=0,dy=y;
        int mx = (x*x + y*y);
        mx = sqrt(mx);

        if(k>y || k>x){
            bx=x;
            by=y;
            cx=x;
            cy=0;
        }
        cout << ax << " " << ay << " " <<  bx << " " << by << endl;
        cout << cx << " " << cy << " " << dx << " " << dy << endl;
    }
}