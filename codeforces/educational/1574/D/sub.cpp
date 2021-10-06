#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
vector<vector<int>> a;
int m;
vector<vector<int>> b;

int main() {
	scanf("%d", &n);
	a.resize(n);
	forn(i, n){
		int c;
		scanf("%d", &c);
		a[i].resize(c);
		forn(j, c) scanf("%d", &a[i][j]);
	}
	scanf("%d", &m);
	b.resize(m);
	forn(i, m){
		b[i].resize(n);
		forn(j, n){
			scanf("%d", &b[i][j]);
			--b[i][j];
		}
	}
	sort(b.begin(), b.end());
	vector<int> ult(n);
	forn(i, n) ult[i] = int(a[i].size()) - 1;
	if (!binary_search(b.begin(), b.end(), ult)){
		forn(i, n) printf("%d ", ult[i] + 1);
		puts("");
		return 0;
	}
	int mx = 0;
	vector<int> ans(n, -1);
	forn(i, m){
		vector<int> tmp = b[i];
		int sum = 0;
		forn(j, n) sum += a[j][tmp[j]];
		forn(j, n) if (tmp[j] != 0){
			--tmp[j];
            forn(k, n){
             printf("%d ", tmp[i] + 1);
            }
            puts("");

			if (!binary_search(b.begin(), b.end(), tmp) && sum - a[j][tmp[j] + 1] + a[j][tmp[j]] > mx){
				mx = sum - a[j][tmp[j] + 1] + a[j][tmp[j]];
				ans = tmp;
			}
			++tmp[j];
		}
	}
	forn(i, n){
		printf("%d ", ans[i] + 1);
	}
	puts("");
}