#include "bits/stdc++.h"
using namespace std;

//0-1 Knapsack
int longestCommonSubsequence(string text1, string text2) {
    int n=text1.length();
    int m=text2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }

            else if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
        }
    }
    return dp[n][m];
}


//LCS
int FindKnapsackRec(int capacity, vector<int>& weights, vector<int>& values, int n, vector<vector<int>>& dp) {
    if (n == 0 || capacity == 0)
        return 0;

    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    if (weights[n - 1] <= capacity) {
        dp[n][capacity] = max(
                values[n - 1] + FindKnapsackRec(capacity - weights[n - 1], weights, values, n - 1, dp),
                FindKnapsackRec(capacity, weights, values, n - 1, dp));
        return dp[n][capacity];
    }
    dp[n][capacity] = FindKnapsackRec(capacity, weights, values, n - 1, dp);
    return dp[n][capacity];
}


int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}