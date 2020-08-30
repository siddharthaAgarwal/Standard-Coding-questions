// { Driver Code Starts
// Initial template
#include <bits/stdc++.h>
using namespace std;

bool isBridge(list<int> adj[], int V, int u, int v);
// Driver Program
int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        list<int> *adj = new list<int>[s];
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        int a, b;
        cin >> a >> b;

        if (isBridge(adj, s, a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends


void dfs(list<int> adj[],int V,int s, vector<bool> &visited)
{
    visited[s]=true;
    
    for(int i:adj[s])
    {
        if(!visited[i])
        {
            dfs(adj,V,i,visited);
        }
    }
}



bool isBridge(list<int> adj[], int V, int s, int e) 
{
    
    vector<bool> visited(V,false);
    
    adj[s].remove(e);
    adj[e].remove(s);
    
    dfs(adj,V,s,visited);
    
    if(!visited[e])
    return true;
    return false;
    
}
