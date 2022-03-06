#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinchange(int coins[] , int sum ,int i){
    //recursion usage
    if(sum==0 ){
        return 1;
    }
    if(sum!=0 && i==0){
        return 0;
    }
    if(sum-coins[i-1]>=0){
        int a = coinchange(coins , sum-coins[i-1], i); 
        int b = coinchange(coins , sum, i-1);
        return a+b;
    }
    else{
        int c = coinchange(coins , sum ,i-1);
        return c;
    }
    
}

int coinchangedp(int coins[] , int sum ,int n){
    //DP usage
    int dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0 ){
                dp[i][j] =0;
            }
            if(j==0){
                dp[i][j] =1;
            }
        }
        
    }
    // dp[0][0] =1;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(j-coins[i-1]>=0){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];

            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }    
    return dp[n][sum];
}


int main(){
    int i = 3;
    int coins[3] ={1,2,3};
    int sum = 4;
    cout<<"in the main "<<endl;
    int c = coinchangedp(coins ,sum ,i);
    // return coinchange(coins , sum ,i);
    cout<<c<<endl;
    // return 0;
}