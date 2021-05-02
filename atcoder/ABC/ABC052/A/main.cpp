# include <bits/stdc++.h>
using namespace std;

int main () {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int S1 = A*B;
	int S2 = C*D;
	
	cerr << A << " " << B << endl;
	cerr << C << " " << D << endl;
	cerr << "S1: " << S1 << endl;
	cerr << "S2: " << S2 << endl;
	
	cout << max(S1, S2) << endl;
	return 0;
}
