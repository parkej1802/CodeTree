#include <iostream>
#include <vector>

using namespace std;

int n, m, s, e, result = 0;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int startNode) {
    visited[startNode] = true;
    for (int i = 0; i < graph[startNode].size(); i++) {
        int neighborNode = graph[startNode][i];
        if (!visited[neighborNode]) {
            result++;
            dfs(neighborNode);
        }
    }
}

int main() {

    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    dfs(1);
    cout << result;
    
    return 0;
}