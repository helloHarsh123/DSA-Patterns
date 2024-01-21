/******************************************************************************
Algorithms for Competitive Programming
Find Cycle in a undirected graph.
*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int s_cycle = -1, e_cycle = -1;
vector< int > parent;

bool dfs(int cur,vector< vector< int > >&adj, vector< bool > &vis)
{
   // cout<< cur<< endl;
    vis[cur] = true;
    for(auto v: adj[cur])
    {
        if(v == parent[cur]) continue;
        if(vis[v])
        {
            s_cycle = v;
            e_cycle = cur;
            return true;
        }
        else{
            parent[v] = cur;
            if(dfs(v,adj,vis)) return true;
        }
    }
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
        adj[y-1].push_back(x-1);
    }
    vector< bool > vis(n, false);
    parent.resize(n, -1);
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == false and dfs(i,adj,vis))
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
        for(auto it: cycle) cout<<it+1<<" ";
        cout<<endl;
    }
    return 0;
}
