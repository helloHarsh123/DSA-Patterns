/******************************************************************************

We use 3 colours to do the job efficiently

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int s_cycle = -1, e_cycle = -1;
vector< int > parent;

bool dfs(int cur,vector< vector< int > >&adj, vector< int > &vis)
{
    vis[cur] = 1;
    for(auto v: adj[cur])
    {
        if(vis[v] == 0 )
        {
            parent[v] = cur;
            if(dfs(v,adj,vis)) return true;
        }
        else if(vis[v] == 1)
        {
            s_cycle = v;
            e_cycle = cur;
            return true;
        }
    }
    vis[cur] = 2;
    return false;
}


int main()
{
    int m,n;
    cin>>n>>m;
    vector< vector< int > >adj(n);
    for(int i =0; i < m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
    }
    vector< int > vis(n, 0);
    parent.resize(n, -1);
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0 and dfs(i,adj,vis))
        {
            break;
        }
    }
    if(s_cycle == -1) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector< int > cycle;
        cycle.push_back(s_cycle);
        for(int i = e_cycle; i != s_cycle; i = parent[i])
        {
           cycle.push_back(i);
        }
        cycle.push_back(s_cycle);
        cout<<cycle.size()<<endl;
        reverse(cycle.begin(), cycle.end());
        for(auto it: cycle) cout<<it+1<<" ";
        cout<<endl;
    }
    return 0;
}
