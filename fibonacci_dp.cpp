#include <iostream>
#include <vector>
using namespace std;

// Memoization
int fibMemo(int n, vector<int>& dp){

    if(n<=1)
        return n;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n]=fibMemo(n-1,dp)+fibMemo(n-2,dp);
}

int main(){

    int n=10;

    vector<int> dp(n+1,-1);

    cout<<"Memoization: "<<fibMemo(n,dp)<<endl;

    // Tabulation

    vector<int> table(n+1);

    table[0]=0;
    table[1]=1;

    for(int i=2;i<=n;i++)
        table[i]=table[i-1]+table[i-2];

    cout<<"Tabulation: "<<table[n];
}
