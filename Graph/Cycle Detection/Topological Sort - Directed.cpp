class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& revedges) {
        /*detect and no printing of the cycle so Topological sort
            find 0 indegree node in cur graph. (if not able to find print cycle = yes)
            remove it and reduce indegree of the outgoing nodes
            repeat  
        */ 
        vector< vector< int > > adj(n);
        vector< int > indegrees(n,0);
        for(auto it: revedges)
        {
            adj[it[1]].push_back(it[0]); indegrees[it[0]]++;
        }
        for(int i =0; i <n; i++)
        {
            int j = 0;
            for(; j < n; j++)
            {
                if(indegrees[j] == 0) break;
            }
            if(j == n) return false; // its a cycle
            indegrees[j]--;
            for(auto it: adj[j])
            {
                indegrees[it]--;
            }
        }
        return true;
    }
};
