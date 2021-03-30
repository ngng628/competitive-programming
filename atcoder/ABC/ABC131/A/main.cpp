# include <bits/stdc++.h>
using namespace std;

int main() {
   string S;
   cin >> S;
   cout << (S[0] == S[1] or S[1] == S[2] or S[2] == S[3] ? "Bad\n" : "Good\n");
}
