#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {

    int V = 5;

    vector<pair<int,int>> graph[5];

    graph[0].push_back({1,2});
    graph[0].push_back({2,4});
    graph[1].push_back({2,1});
    graph[1].push_back({3,7});
    graph[2].push_back({4,3});
    graph[3].push_back({4,1});

    vector<int> dist(V, INF);

    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){

        int node = pq.top().second;
        int distance = pq.top().first;

        pq.pop();

        for(auto edge : graph[node]){

            int next = edge.first;
            int weight = edge.second;

            if(distance + weight < dist[next]){

                dist[next] = distance + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout<<"Shortest Distance from Node 0\n";

    for(int i=0;i<V;i++)
        cout<<"Node "<<i<<" = "<<dist[i]<<endl;
}
