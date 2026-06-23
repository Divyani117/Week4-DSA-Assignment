#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10];
bool visited[10];

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            DFS(neighbor);
    }
}

void BFS(int start) {
    bool visitedBFS[10] = {false};
    queue<int> q;

    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visitedBFS[neighbor]) {
                visitedBFS[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);

    cout << "DFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    return 0;
}
