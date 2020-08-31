// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

void getSum(vector<int> &A, int sum,  vector<vector<int>> &res, vector<int> v,int ind)
{
    if(sum==0)
    {
        res.push_back(v);
        return;
    }
    
    // if(sum<0)
    //     return;
//     int s=0;   
    for(int i=ind;i<A.size();i++)
    {
        if(sum-A[i]>=0)
        {
        v.push_back(A[i]);
        getSum(A,sum-A[i],res,v,i);
        v.pop_back();
        }
    }
    
}


vector<vector<int> > combinationSum(vector<int> &A, int B) 
{
    vector<vector<int>> res;
    
    sort(A.begin(), A.end());
    
    A.erase(unique(A.begin(),A.end()),A.end());
  
    vector<int> v;
    getSum(A,B,res,v,0);
    
    return res;
    
}

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int> > result;
   		result=combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
