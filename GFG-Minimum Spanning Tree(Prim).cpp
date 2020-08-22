// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int get_min(vector<bool> visited,vector<int> distance,int V)
{
    int ind=-1,check=INT_MAX;
    for(int i=0;i<V;i++)
    {
        if(distance[i]<=check  && (!visited[i]))
        {
            check=distance[i];
            ind=i;
        }
    }
    return ind;
}



int spanningTree(int V, int E, vector<vector<int>> &g) 
{

  

 int sum=0;
 vector<int> dist(V,INT_MAX);
    vector<bool> visited(V);
    
    dist[0]=0;   

    for(int count=0;count<V-1;count++)
    {
        int u=get_min(visited,dist,V);
        // cout<<"u = "<<u<<" \n";
        
        visited[u]=true;
        for(int i=0;i<V;i++)
        {
            if((!visited[i])  && dist[i]>(g[u][i]))
            {
                dist[i]=g[u][i];
                //sum+=g[u][i];
            }
        }
        

    }
  
    return accumulate(dist.begin(),dist.end(),0);
}
