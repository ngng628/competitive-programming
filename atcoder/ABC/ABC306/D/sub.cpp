# include <bits/stdc++.h>
using namespace std;

int main() {
   multiset<int> st;
   st.insert(0);
   st.insert(0);
   st.insert(0);
   st.insert(0);
   st.insert(0);
   cout << *prev(st.end()) << endl;
}