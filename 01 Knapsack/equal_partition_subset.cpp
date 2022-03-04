class Solution{
public:
    // Correct Recursive code but TLE occured
    int val=0;
    void partition(int N , int arr[] , int count){
        if(N==0 || count==0){
            //BC
            if(count==0){
                val=1;
            }
            return;
        }
        if(count - arr[N-1]>=0){
            partition(N-1 ,arr , count-arr[N-1]);//took
            partition(N-1,arr ,count);
        }
        else{
            partition(N-1 ,arr,count);
        }
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int count = 0;
        for(int i=0;i<N;i++){
            count += arr[i];
        }
        // cout<<count<<endl;
        if(count%2==1){
            return 0;
        }else{
            count = count/2;
            partition(N,arr,count);
        }
        
        return val;
    }
};
