#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a = stoi(s.substr(0, 2)); // Convert string to integer
        if(s.substr(0,2)=="00"){
            cout << "12"+s.substr(2,3)+" AM"<< endl;
        }
        if (a < 12 && a>0) {
            cout << s + " AM" << endl;
        }
        if(a==12){
            cout << s + " PM" << endl;
        }
        
        else if(a>12) {
            if(a-12 <10){
            cout << "0"+to_string(a - 12) + s.substr(2) + " PM" << endl;
        }
           else{
            cout << to_string(a - 12) + s.substr(2) + " PM" << endl;
        }
    }
    }
    return 0;
}
