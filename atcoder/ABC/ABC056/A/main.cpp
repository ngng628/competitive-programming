# include <bits/stdc++.h>
using namespace std;

int main()
{
    char a, b;
    cin >> a >> b;
    bool AtCoDeer  = (a == 'H');
    bool TopCoDeer = (b == 'H');

    char ans[2] = {'D', 'H'};


    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand2bit(0, 1);

    cout << ans[rand2bit(mt)] << endl;


    return 0;
}
