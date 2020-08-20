int minSwaps(int arr[], int N){

    pair<int,int> a[N];
    
    for(int i=0;i<N;i++)
    {
        a[i]= make_pair(arr[i],i);
    }
    
    sort(a,a+N);
    
    vector<bool> visited(N,false); 
    int ans=0;
    for(int i=0;i<N;i++)
    {
        if(visited[i] || a[i].second==i)
        continue;
        
        int cycle=0;
        int j=i;
        while(!visited[j])
        {
            visited[j]=true;
            j=a[j].second;
            
            cycle++;
        }
        
        if(cycle>0)
        ans+=(cycle-1);
    }
    
    return ans;
    

}
