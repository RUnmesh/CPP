//https://www.spoj.com/problems/EAGLE1/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define f(i, start, end, interval) for(ll i = start; i < end; i = i + interval)
#define cf(i, start, end, interval) for(ll i = start; i <= end; i = i + interval)
#define rf(i, start, end, interval) for(ll i = start; i >= end; i = i + interval)
#define rangef(item, container) for(const auto& item: container)
#define all(container) (container).begin(), (container).end()


ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b/gcd(a,b);}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll tc;
	cin >> tc;
	f(t, 0 , tc, 1) {
		ll num_intersections;
		cin >> num_intersections;

		unordered_map<int, vector<pair<int, int>>> adj_list;
		f(i, 1, num_intersections, 1) {
			ll start_intersection, end_intersection, num_dogs;
			cin >> start_intersection >> end_intersection >> num_dogs;

			adj_list[start_intersection-1].push_back({end_intersection-1, num_dogs});
			adj_list[end_intersection-1].push_back({start_intersection-1, num_dogs});
		}

		vector<vector<ll>> max_dogs_in_subtree(num_intersections);
		struct DfsStack1Data {
			ll intersection;
			ll parent;
			int state;
		};
		stack<DfsStack1Data>dfs_stack1;
		dfs_stack1.push({0,-1,0});
		while(!dfs_stack1.empty()) {
			auto& [cur_intersection, parent, state] = dfs_stack1.top();
			dfs_stack1.pop();

			if (state == 1) {
				for(const auto& [child, num_dogs]: adj_list[cur_intersection]) {
					if (child == parent){
					 	max_dogs_in_subtree[cur_intersection].push_back(0);
						continue;
					}
					auto max_dogs = max_element(all(max_dogs_in_subtree[child]));
					if (max_dogs == max_dogs_in_subtree[child].end())
						max_dogs_in_subtree[cur_intersection].push_back(num_dogs);
					else
						max_dogs_in_subtree[cur_intersection].push_back(num_dogs+*max_dogs);
				}
			}

			if (state == 0) {
				dfs_stack1.push({cur_intersection, parent, 1});
				for(const auto& [child, num_dogs]: adj_list[cur_intersection]) {
					if (child != parent)
						dfs_stack1.push({child, cur_intersection, 0});
				}
			}
		}

		vector<ll>ans(num_intersections);
		struct DfsStack2Data{
			ll intersection;
			ll parent;
			ll parent_max;
		};
		stack<DfsStack2Data>dfs_stack2;
		dfs_stack2.push({0, -1, 0});

		while (!dfs_stack2.empty()) {
			auto [cur_intersection, parent, parent_max] = dfs_stack2.top();
			dfs_stack2.pop();

			ans[cur_intersection] = max(parent_max, *max_element(all(max_dogs_in_subtree[cur_intersection])));

			vector<ll> r_max_dogs(adj_list[cur_intersection].size());
			ll cur_r_max = 0;
			rf(i, r_max_dogs.size()-1, 0, -1) {
				ll cur_subtree_max_dogs = max_dogs_in_subtree[cur_intersection][i];
				r_max_dogs[i] = cur_r_max = max(cur_r_max, cur_subtree_max_dogs);
			}

			ll cur_l_max = 0;
			f(i, 0, r_max_dogs.size(), 1) {
				auto& [child, num_dogs] = adj_list[cur_intersection][i];
				if (child == parent)
					continue;
				ll child_max = num_dogs + max(parent_max, max(cur_l_max, (i == r_max_dogs.size()-1? 0:r_max_dogs[i+1])));
				dfs_stack2.push({child, cur_intersection, child_max});
				cur_l_max = max(cur_l_max, max_dogs_in_subtree[cur_intersection][i]);
			}
		}

		f(i,0,num_intersections, 1)
			cout << ans[i]<<' ';
		cout<<'\n';
	}

	return 0;
}