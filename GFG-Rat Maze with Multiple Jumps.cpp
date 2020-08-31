// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends




bool isSafe(int i,int j,vector<int> m[],int n)
{
    if(i>=0 && j>=0 && i<n && j<n && m[i][j]!=0)
    return true;
    return false;
}

bool getPath(vector<int> m[], int n,int i,int j, vector<vector<int>> &ans)
{
    
    ans[i][j]=1;
    if(i==n-1 && j==n-1)
    {
        return true;   
    }
    
    
    for(int ind=1;ind<=m[i][j];ind++)
    {
        
        if(isSafe(i,j+ind,m,n))
        {
            if(getPath(m,n,i,j+ind,ans))
            {
                ans[i][j+ind]=1;
                return true;
            }
        }
      
        if(isSafe(i+ind,j,m,n))
        {
            if(getPath(m,n,i+ind,j,ans))
            {
                ans[i+ind][j]=1;
                return true;
            }
        }
    }
    
    ans[i][j]=0;
    return false;
}




void solve(int N, vector<int> maze[]) {
   
    vector<vector<int>> v(N,vector<int> (N,0));
    
      
      maze[N-1][N-1]=1;
     if(!getPath(maze,N,0,0,v))
     {
         cout<<"-1\n";
         return;
     }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }

}
