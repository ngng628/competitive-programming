# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string S;

int main()
{
    cin >> S;

    string S1;
    S1.push_back(S[0]);
    S1.push_back(S[1]);
    string S2;
    S2.push_back(S[2]);
    S2.push_back(S[3]);


    if (S1 == "00" && S2 == "00")
    {
        cout << "NA" << "\n";
        return 0;
    }

    int a = atoi(S1.c_str());
    int b = atoi(S2.c_str());

    if (0 < a && a <= 12 && 0 < b && b <= 12)
    {
        cout << "AMBIGUOUS" << "\n";
        return 0;
    }

    if (S2 == "00" && 1 <= a && a <= 12)
    {
        cout << "MMYY" << "\n";
        return 0;
    }

    if (S1 == "00" && 1 <= b && b <= 12)
    {
        cout << "YYMM" << "\n";
        return 0;
    }
    
    if (1 <= b && b <= 12)
    {
        cout << "YYMM" << "\n";
        return 0;
    }

    if (1 <= a && a <= 12)
    {
        cout << "MMYY" << "\n";
        return 0;
    }
    
    cout << "NA" << "\n";

    return 0;
}
