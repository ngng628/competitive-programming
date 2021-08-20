# include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	function<int(int)> rec = [&](int n) {
		if (n == 1 or n == 2) return 1;
		return rec(n-1) + rec(n-2);
	};
	
	cout << rec(n) << endl;
}
