// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends

bool isSafe(int grid[N][N],int i,int j,int k)
{
    for(int n=0;n<N;n++)
    {
        if(grid[i][n]==k || grid[n][j]==k)
        return false;
    }
    
    int s=sqrt(N);
    int rs=i-i%s;
    int cs=j-j%s;
    
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
        {
            if(grid[i+rs][j+cs]==k)
                return false;
        }
    
    return true;
}
bool SolveSudoku(int grid[N][N])  
{ 
    int i,j;
    bool flag=false;
    
    for( i=0;i<N;i++)
    {
        for( j=0;j<N;j++)
            if(grid[i][j]==0)
            {
                flag=true;
                break;
            }
        if(flag)
        break;
    }            
            
  //    cout<<i<<" "<<j<<"\n";
    if(i==N && j==N)
    return true;
    
    for(int k=1;k<=N;k++)
    {
        if(isSafe(grid,i,j,k))
        {
            grid[i][j]=k;
            if(SolveSudoku(grid))
                return true;
            grid[i][j]=0;
        }
    }
    return false;
}

void printGrid (int grid[N][N]) 
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
    }
}
