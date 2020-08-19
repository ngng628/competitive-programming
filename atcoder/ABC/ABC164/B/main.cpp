# include <bits/stdc++.h>
using namespace std;
static const bool TAKAHASHI_TURN = false;
static const bool AOKI_TURN = true;

class Monster {
public:
    Monster() = default;

    void attack(Monster& enemy) {
        enemy.m_hitPoint -= min(enemy.m_hitPoint, m_attackPoint);
    }

    bool isDead() {
        return m_hitPoint == 0;
    }

    void read() {
        cin >> m_hitPoint >> m_attackPoint;
    }

private:
    int m_hitPoint;
    int m_attackPoint;
};

int main() {
    Monster takahashi, aoki;
    takahashi.read();
    aoki.read();

    for (bool turn = TAKAHASHI_TURN; !takahashi.isDead() and !aoki.isDead(); turn = !turn) {
        switch (turn) {
            case TAKAHASHI_TURN:
                takahashi.attack(aoki);
                break;
            case AOKI_TURN:
                aoki.attack(takahashi);
                break;
        }
    }

    cout << (aoki.isDead() ? "Yes" : "No") << endl;

    return 0;
}

