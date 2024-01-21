/******************************************************************************

Floyd Warshall(APSP)
We can also reconstruct path for any 2 nodes. Also we can detect -ve cycle if any.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

void floydWarshall(vector< vector< int > > &adj, vector< vector< int > > &next, int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(adj[i][k]!=INT_MAX and adj[k][j]!=INT_MAX and adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void negcycle(vector< vector< int > > &adj, vector< vector< int > > &next, int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(adj[i][k]!=INT_MAX and adj[k][j]!=INT_MAX and adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = INT_MIN;
                    next[i][j] = -1;
                }
            }
        }
    }
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
   // n++;
    vector< vector< int > > adj(n, vector<int> (n,INT_MAX));
    vector< vector< int > > next(n, vector<int> (n, -1));
    for(int i = 0; i < n; i++) adj[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a][b] = c;
        adj[b][a] = c;
        next[a][b] = b;
        next[b][a] = a;
    }
    floydWarshall(adj, next, n);
    negcycle(adj, next, n);
    for(int i = 0; i < q; i++)
    {
        int x, y; 
        cin>>x>>y;
        x--;y--;
        if(adj[x][y] == INT_MAX) 
        {
            cout<<" -1"<<endl;
            continue;
        }
        if(adj[x][y] == INT_MIN) 
        {
            cout<<"has -ve cycle"<<endl;
            continue;
        }
        cout<< x <<","<<y<< " => " << adj[x][y] <<endl;
        cout<<"path: ";
        int z = x;
        while(z!=y)
        {
            cout<<z<<" ";
            z = next[z][y];
        }
        cout<<z<<" ";
        cout<<endl;
    }
    return 0;
}
