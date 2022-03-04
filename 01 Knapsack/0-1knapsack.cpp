// this is a classic problem of DP and one of the most famous problem

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void knapsack(int n , int wt[], int val[] , int W , int totalval){
    //this is normal recurison bache bhi kr lenge with void function
    if(n==0 || W==0){
        //bc
        v.push_back(totalval);
        return;
    }
    if(W-wt[n-1]>=0){
        knapsack(n-1 , wt ,val ,W-wt[n-1] ,totalval+val[n-1]);
        knapsack(n-1 , wt , val ,W , totalval);
    }
    else{
        knapsack(n-1 ,wt ,val ,W ,totalval);
    }
}

int knapsack(int n , int wt[] , int val[] , int W ){
    //this is recursion with int function
    // understand recursive integer function with fibonacci series
    if(n==0){
        //BC
        return 0;
    }
    if(W-wt[n-1]>=0){
        int a = val[n-1]+ knapsack(n-1 , wt ,val ,W-wt[n-1]);
        int b = knapsack(n-1 , wt , val ,W );
        return max(a,b);
    }
    else{
        int c =knapsack(n-1 ,wt ,val ,W);
        return c;
    }

}

//this is farzi DP => recursion + memoization
int t[1002][1002];//t[n+1][W+1];
// memset(t ,-1 , sizeof(t));

int knapsack(int n , int wt[] , int val[] , int W ){
    //this is recursion with int function
    // understand recursive integer function with fibonacci series
    if(n==0||W==0){
        //BC
        return 0;
    }
    if(t[n][W]!=-1){
        return t[n][W];
    }
    if(W-wt[n-1]>=0){
        int a = val[n-1]+ knapsack(n-1 , wt ,val ,W-wt[n-1]);
        int b = knapsack(n-1 , wt , val ,W );
        t[n][W] = max(a,b);
        return max(a,b);
    }
    else{
        int c =knapsack(n-1 ,wt ,val ,W);
        t[n][W] =c;
        return c;
    }
}

//this is pure dp also called top-down approach

int knapsack2(int n ,int wt[] , int val[] , int W){
    // array of t[n+1][W+1]
    // because here the last element of the matrix will be t[n][W]
    // this is the crux of whole dp
    int dp[n+1][W+1];
    for(int i=0;i<n;i++){
        for (int j = 0; j < W; j++)
        {
            if(i==0||j==0){
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < W; j++)
        {
            //W--> j and n-->i ho gya
            if(j-wt[i] >=0){
                return max( val[i-1] + dp[n-1][j-wt[i-1]] , dp[n-1][j]);

            }else{
                return dp[n-1][j];
            }
        }
        
    }
    return dp[n][W];
    
}


int main(){
    //take the max of the vector v in totalval
    // knapsack of void type
    sort(v.begin() , v.end());
    return v[-1];
    return 0;
}