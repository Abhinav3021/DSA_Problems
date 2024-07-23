#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            /* code */
            cin >> arr[i];
        }
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            sum+=abs(arr[i]);
        }
        cout << sum << endl;

    }}
        