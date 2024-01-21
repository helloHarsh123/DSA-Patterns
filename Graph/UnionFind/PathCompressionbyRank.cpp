class Solution {
public:
    int parent[201];
    int rank[201] = {0};
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        make_set(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(M[i][j])
                    union_sets(i,j);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if( i == parent[i] ) cnt++;
        }
        return cnt;
    }
    void make_set(int n){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_set(int v){
        if(v == parent[v]) 
            return v;
        return parent[v] = find_set(parent[v]); // path compression
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a!=b)
        {
            if(rank[a] > rank[b]) // attach smaller rank to the higher rank and retain the highest rank
            {
                parent[b] = a;
            }
            else if(rank[a] < rank[b]){
                parent[a] = b;
            }
            else{ // if both same than attach and raise rank by 1
                parent[a] = b;
                rank[a]++;
            }
        }
    }
};
