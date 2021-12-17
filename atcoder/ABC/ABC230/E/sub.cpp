
#include <bits/stdc++.h>

using namespace std;


int main(void) {
	long long n, ans, k;
	cin >> n;

	for (long long i = 1; i <= n; i++) {
		if (i*i <= n)k = i;
		else break;
	}

	ans = 0;
	for (long long i = 1; i <= k; i++)ans += ((n / i) - (n / (i + 1)))*i;
	for (long long i = 1; i <= n / (k + 1); i++)ans += (n / i);
	
	cout << ans << endl;
	return 0;
}
