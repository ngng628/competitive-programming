# include <iostream>
using namespace std;

int main() {
   long long A, B, K;
   cin >> A >> B >> K;
   cout << max(0LL, A-K) << " " << max(0LL, B-max(0LL, K-A)) << endl;
}