#include<bits/stdc++.h>
using namespace std ;
vector<int> nums;
vector<int> dp;

int lis(int i){
    if(dp[i]!=-1){return dp[i];}
    int ans=1;
    for(int j=0;j<i;j++){
        if(nums[i]>nums[j]){
            ans=max(ans,lis(j)+1);
        }       
    }
    return dp[i]=ans;
}

int main(){
    int n;
    cin >> n;
    nums.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int answer=0;
    for(int i=0;i<n;i++){
        answer=max(answer,lis(i));
    }
    cout << answer;

}


