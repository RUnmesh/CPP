#include <bits/stdc++.h>
using namespace std;

// O(number of vertices + number of edges)
void RecursiveDfs(long long curr_v, unordered_map<long long, vector<long long>>& adj_list, vector<bool>& visited) {
	visited[curr_v] = true;

	for (const auto& next_v : adj_list[curr_v]) {
		if (!visited[next_v]) RecursiveDfs(next_v, adj_list, visited);
	}
}

// O(number of vertices + number of edges)
void IterativeDfs(long long start_v, unordered_map<int, vector<int, int>>& adj_list, vector<bool>& visited) {
	stack<long long> dfs_stack;
	dfs_stack.push(start_v);

	while (!dfs_stack.empty()) {
		long long curr_v = dfs_stack.top();
		dfs_stack.pop();

		visited[curr_v] = true;
		for (const auto& next_v: adj_list[curr_v]) {
			if (!visited[next_v]) dfs_stack.push(next_v);
		}
	}
}