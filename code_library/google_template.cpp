#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include<algorithm>
using namespace std;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
int work(int casen,int n) {
	vector<vector<int>> nums(n, vector<int>());
	vector<int> visit(n, 0);
	for (int i = 0; i < n; i++) {
		visit[i] = i;
	}
	int a, b;
	set<int> cycle;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a--;
		b--;
		nums[a].push_back(b);
		nums[b].push_back(a);
		if (a == b)
			continue;
		int na = visit[a];
		int nb = visit[b];
		while (visit[na] != na)
			na = visit[na];
		while (visit[nb] != nb)
			nb = visit[nb];
		visit[max(b,a)] = min(b,a);
		if (flag&&na == nb) {
			flag = false;
			cycle.insert(a);
			cycle.insert(b);
			
		}
	}

	cout << "Case #" << casen << ": ";
}
int main() {
	int t, n, m;
	cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
	for (int i = 1; i <= t; ++i) {
		cin >> n ;  // read n and then m.
		work(i, n);
		//cout << "Case #" << i << ": " << work(i,n)<< endl;
		// cout knows that n + m and n * m are ints, and prints them accordingly.
		// It also knows "Case #", ": ", and " " are strings and that endl ends the line.
	}
	system("pause");
	return 0;
}