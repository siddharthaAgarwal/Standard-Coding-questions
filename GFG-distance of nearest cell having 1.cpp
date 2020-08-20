// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

vector <vector <int> > nearest(vector<vector<int>> &arr, int row, int col);
int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        print (nearest(graph, row, col), row, col);
    }

    return 0;
}
// } Driver Code Ends


/*  Function to find the distance of nearest cell having 1

*   mat: The input matrix of 0s and 1s
*   N, M: rows and cols in given matrix
*   Return the resultant matrix of size (N x M) representing the nearest distance 1 from each cell
*/



bool isSafe(int i,int j,int N,int M,vector<vector<int>> &res,int  time)
{
    return i>=0 && i<N && j>=0 && j<M && res[i][j]>(time+1);
}
vector <vector <int> > nearest(vector<vector<int>> &mat, int N, int M) 
{

    vector<vector<int>> res(N);
    
    for(int i=0;i<N;i++)
    {
        vector<int> v(M,INT_MAX);
        res[i]=v;
    }
    
    
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]==1)
            {
                q.push(make_pair(make_pair(i,j),0));   
                res[i][j]=0;
          //      cout<<i<<" "<<j<<" \n";
            }
        }
    }
    
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
        
            int row[]={-1,0,0,1};
            int col[]={0,-1,1,0};
        
            for(int i=0;i<4;i++)
            {
                int a=x+row[i], b=y+col[i];
                
                if(isSafe(a,b,N,M,res,time))
                {
                    q.push(make_pair(make_pair(a,b),time+1));
                    res[a][b]=time+1;
                }
            }
        }
        
        return res;
        
    }

    
    
