// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    
    int lmax=arr[0];
    int rmax=arr[n-1];
    
    int l=1,r=n-1;
    int res=0;
    
    while(l<=r)
    {
        
        if(lmax<rmax)
        {
            if(arr[l]>lmax)
                lmax=arr[l];
            else
                res+=lmax-arr[l];
                l++;
        }
        else//if(lmax<rmax)
        {
            if(arr[r]>rmax)
                rmax=arr[r];
            else
                res+=rmax-arr[r];
                r--;
        }
        
        
    }
    
    return res;


    // Your code here
    
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
