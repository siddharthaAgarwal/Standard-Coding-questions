// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main() {
    // size of square board
    int t;
    cin >> t;
    while (t--) {
        int N;
        int a, b, c, d;
        cin >> N;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a, b};
        int targetPos[] = {c, d};
        cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size

bool isSafe(int i, int j,vector<vector<bool>> &v,int N)
{
    return (i>=0 && i<N && j>=0 && j<N && (!v[i][j]));
}


int minStepToReachTarget(int knightPos[], int targetPos[], int N) 
{
    vector<vector<bool>> v;
    if(knightPos[0]==targetPos[0] && targetPos[1]==knightPos[1])
    return 0;
    for(int i=0;i<N;i++)
    {
        vector<bool> temp(N,false);
        v.push_back(temp);
    }
    
    queue<pair<pair<int,int >,int>> q;
    q.push(make_pair(make_pair(knightPos[0],knightPos[1]),0));
    
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        
        int time=q.front().second;
        q.pop();
        int row[]={-1,-2,-2,-1,1,2,2,1};
        int col[]={-2,-1,1,2,-2,-1,1,2};
        
        for(int i=0;i<8;i++)
        {
            int a=x+row[i];
            int b=y+col[i];
            
            if(a==targetPos[0] && b==targetPos[1])
            {
                return time+1;
            }
            if(isSafe(a,b,v,N))
            {
                q.push(make_pair(make_pair(a,b),time+1));
                v[a][b]=true;
            }
        }
        
    }
    
    
    
}
