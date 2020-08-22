// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

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



vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dist(V,INT_MAX);
    vector<bool> visited(V);
    dist[src]=0;
    
    
    for(int count=0;count<V-1;count++)
    {
        int u=get_min(visited,dist,V);
        visited[u]=true;
        
        for(int i=0;i<V;i++)
        {
            if((!visited[i]) && g[u][i] && dist[u]!=INT_MAX && dist[i]>(dist[u]+g[u][i]))
            {
                dist[i]=dist[u]+g[u][i];
            }
        }
        
    }
    
   // cout<<"\n";
    
    return dist;

}
