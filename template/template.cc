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

	return 0;
}