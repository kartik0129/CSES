#include <bits/stdc++.h>
using namespace std;

// Function to perform topological sort and find the order
// in which courses can be completed
vector<int> solve(int n, vector<vector<int> >& adj,
                  vector<int>& indeg)
{
    queue<int> q;
    vector<int> ans;
    // Initialize queue with nodes having in-degree 0
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0)
            q.push(i);
    }
    // Iterate till q is not empty
    while (!q.empty()) {
        // Pop the front node of the queue
        int node = q.front();
        q.pop();
        // Push the front node to the answer
        ans.push_back(node);
        // Update in degree of adjacent nodes
        for (int child : adj[node]) {
            indeg[child] -= 1;
            if (indeg[child] == 0) {
                q.push(child);
            }
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n + 1);
    vector<int> indeg(n + 1, 0);
    // Build directed graph and calculate in-degrees
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int u = a;
        int v = b;
        graph[u].push_back(v);
        indeg[v] += 1;
    }

    // Get the topological sort
    vector<int> ans = solve(n, graph, indeg);

    // Print the result
    if (ans.size() != n) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    return 0;
}
