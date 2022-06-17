#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll n, m;
ll s[200005], x[15];
ll b[200005];

int main(void)
{
  cin >> n >> m;
  for(int i = 1; i <= n-1; i++) cin >> s[i];
  for(int i = 1; i <= m; i++) cin >> x[i];
  
  for(int i = 2; i <= n; i++) b[i] = s[i-1] - b[i-1];
  for (int i = 1; i <= n; ++i) {
     cout << b[i] << " \n"[i == n];
  }
  
  map<ll, ll> mp;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ll c = x[j] - b[i];
      if(i % 2 == 0) c *= -1;
      mp[c]++;
    }
  }
  
  ll ans = 0;
  for(auto p : mp) ans = max(ans, p.second);
  cout << ans << endl;
  
  return 0;
}
