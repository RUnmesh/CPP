#include <bits/stdc++.h>
using namespace std;

// O(number of vertices + number of edges)
void IterativeBfs(long long start_v, unordered_map<long long, vector<long long>>& adj_list, vector<long long>& visited) {
    queue<long long> bfs_queue;
    bfs_queue.push(start_v);

    while (!bfs_queue.empty()) {
        long long curr_v = bfs_queue.front();
        bfs_queue.pop();

        visited[curr_v] = true;
        for (const auto& next_v: adj_list[curr_v]) {
            if(!visited[next_v]) bfs_queue.push(next_v);
        }
    }
}