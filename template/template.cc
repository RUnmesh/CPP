#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define f(i, start, end, interval) for(ll i = start; i < end; i = i + interval)
#define cf(i, start, end, interval) for(ll i = start; i <= end; i = i + interval)


ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	return 0;
}