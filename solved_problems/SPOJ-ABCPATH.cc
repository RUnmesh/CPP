// https://www.spoj.com/problems/ABCPATH/s
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define f(i, start, end, interval) for(ll i = start; i < end; i = i + interval)
#define cf(i, start, end, interval) for(ll i = start; i <= end; i = i + interval)
#define rangef(item, container) for(const auto& item: container)


ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b/gcd(a,b);}

int main()
{
	struct BfsQueueData {
		ll row;
		ll col;
	};

	ll tc = 1;
	while(true) {
		ll h, w;
		cin >> h >> w;
		if (h == 0 && w == 0) break;

		queue<BfsQueueData> bfs_queue;
		vector<vector<char>> grid(h, vector<char>(w));

		ll ans = 0;
		f(i,0,h,1) {
			f(j,0,w,1) {
				cin>> grid[i][j];
				if (grid[i][j] == 'A') bfs_queue.push({i, j});
			}
		}

		auto is_valid = [&h, &w](ll row, ll col) {
			return row >= 0 && row < h && col >= 0 && col < w;
		};
		vector<pair<ll,ll>>dir_vector = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0, 1}, {1,-1}, {1, 0}, {1,1}};
		vector<vector<bool>> visited(h, vector<bool>(w, false));

		while(!bfs_queue.empty()) {
			auto& [row, col] = bfs_queue.front();
			bfs_queue.pop();

			ans = max(ans, (ll)grid[row][col] - 'A' + 1);
			if (visited[row][col]) continue;
			visited[row][col] = true;

			rangef(dir, dir_vector) {
				ll new_row = row + dir.first;
				ll new_col = col + dir.second;
				if (is_valid(new_row, new_col) && grid[row][col]+1 == grid[new_row][new_col])
					bfs_queue.push({new_row, new_col});
			}

		}

		cout << "Case " << tc++ << ": " << ans << '\n';
	}

	return 0;
}