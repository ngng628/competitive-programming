# include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<string> ans;
    if (n & 1)
    {
        for (int i = n-1; i >= 0; i-=2)
        {
            ans.push_back(a[i]);
            cout << a[i] << endl;
        }
        for (int i = 1; i < n-1; i+=2)
        {
            cout << a[i] << endl;
        }
    }
    else
    {
        vector<string> sub;
        for (int i = 0; i < n-1; ++i)
        {
            sub.push_back(a[i]);
        }

        cout << a[n-1] << endl;
        for (int i = n-3; i >= 0; i -= 2)
        {
            cout << sub[i] << endl;
        }
        for (int i = 0; i <= n-2; i += 2)
        {
            cout << sub[i] << endl;
        }
    }


    return 0;
}
