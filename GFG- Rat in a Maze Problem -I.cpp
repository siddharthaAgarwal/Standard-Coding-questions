// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

bool isSafe(int i,int j,int m[MAX][MAX],int n)
{
    if(i>=0 && j>=0 && i<n && j<n && m[i][j]==1)
    return true;
    return false;
}

void getPath(int m[MAX][MAX], int n,int i,int j, vector<string>&v, string s)
{
    if(i==n-1 && j==n-1)
    {
        v.push_back(s);
      //  cout<<"s("<<s<<")";
        return;   
    }
    
    m[i][j]=0;
    if(isSafe(i+1,j,m,n))
        getPath(m,n,i+1,j,v,s+"D");
    if(isSafe(i,j-1,m,n))
        getPath(m,n,i,j-1,v,s+"L");
    if(isSafe(i,j+1,m,n))
        getPath(m,n,i,j+1,v,s+"R");
    if(isSafe(i-1,j,m,n))
        getPath(m,n,i-1,j,v,s+"U");
        
        m[i][j]=1;
    
    
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> v;
    
    if(isSafe(0,0,m,n))
      getPath(m,n,0,0,v,"");
    
    return v;
    
}
