// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends


long long solve(int N, int M) {

    long long temp=0;
    
    for(long long i=0;i<N;i++)
    {
        for(long long j=0;j<M;j++)
        {
            int c=1;
            long long row[]={-1,-2,-2,-1,1,2,2,1};
            long long col[]={-2,-1,1,2,-2,-1,1,2};
            for(long long k=0;k<8;k++)
            {
                long long x=i+row[k];
                long long y=j+col[k];
                
                if(x>=0 && x<N && y>=0 &&y<M)
                {
                    c++;
                }
            }
            temp=(temp+(N*M)-(c))%1000000007;
        }
    }
    return temp;
    
}
