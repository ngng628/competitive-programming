// seed=-7864744926218581000
// seed=-4990642941878485000
// seed=-3305604035520763000
// seed=8575860244365085000
// seed=-7570900271031690000
// seed=7288848366358225000

# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < int(n); i++)
constexpr int OO = 1001001001;
using namespace std;
template <class T> bool chmin(T& a, T b) { return a > b && (a = b, true); }
template <class T> bool chmax(T& a, T b) { return a < b && (a = b, true); }

pair<vector<vector<int>>, vector<vector<int>>> shortest_path(const vector<vector<int>>& graph) {
   int n = graph.size();
   vector res(n, vector<int>(n, OO));
   vector pre(n, vector<int>(n, -1));

   for (int s = 0; s < n; s++) {
      queue<int> que({s});
      vector<int>& dist = res[s];
      vector<int>& fukugen = pre[s];
      dist[s] = 0;
      while (!que.empty()) {
         int u = que.front();
         que.pop();
         for (int v : graph[u]) {
            if (dist[v] != OO) continue;
            dist[v] = dist[u] + 1;
            fukugen[v] = u;
            que.push(v);
         }
      }
   }

   return make_pair(res, pre);
}

struct Cell {
   int type;
   int n_resources;
   int n_my_ants;
   int n_opp_ants;
   array<int, 6> neigh;
};

struct Query {
   int type;
   int index, strength;
   int index1, index2;
   string txt;
   bool operator <(const Query& other) const {
      auto t1 = make_tuple(type, index, strength, index1, index2, txt);
      auto t2 = make_tuple(other.type, other.index, other.strength, other.index1, other.index2, other.txt);
      return t1 < t2;
   }
};

int main() {
   int n_cells;
   cin >> n_cells;
   cin.ignore();
   vector<Cell> cells(n_cells);
   vector<vector<int>> graph(n_cells);
   rep (i, n_cells) {
      cin >> cells[i].type >> cells[i].n_resources;
      for (int& nei : cells[i].neigh) {
         cin >> nei;
         if (nei != -1) {
            graph[i].push_back(nei);
         } 
      }
      cin.ignore();
   }

   int n_bases;
   cin >> n_bases;
   cin.ignore();
   vector<int> my_bases(n_bases), opp_bases(n_bases);
   rep (i, n_bases) {
      cin >> my_bases[i];
      cin.ignore();
   }
   rep (i, n_bases) {
      cin >> opp_bases[i];
      cin.ignore();
   }

   auto [dist, preroute] = shortest_path(graph);

   constexpr int EGG = 1;
   constexpr int CRYSTAL = 2;

   bool fst = true;
   for(int turn = 0; ; turn++) {
      int sum_of_my_ants = 0, sum_of_opp_ants = 0;
      int sum_of_crystals = 0;
      int sum_of_eggs = 0;
      int sum_of_egg_ants = 0;
      rep (i, n_cells) {
         cin >> cells[i].n_resources >> cells[i].n_my_ants >> cells[i].n_opp_ants;
         cin.ignore();
         sum_of_my_ants += cells[i].n_my_ants;
         sum_of_opp_ants += cells[i].n_opp_ants;
         if (cells[i].type == CRYSTAL) sum_of_crystals += cells[i].n_resources;
         if (cells[i].type == EGG) {
            sum_of_eggs += cells[i].n_resources;
            sum_of_egg_ants += cells[i].n_my_ants;
         }
      }

      // 基地からの距離が近い順に並べる
      vector<tuple<int, int, int>> dists;
      rep (i, n_cells) {
         auto& c = cells[i];
         if (c.type == 0) continue;
         if (c.n_resources <= 0) continue;
         int a = 10*cells[i].n_my_ants, o = 10*cells[i].n_opp_ants;
         for (int nei : graph[i]) { a += cells[nei].n_my_ants; o += cells[nei].n_opp_ants; }
         if (a < o && c.n_resources < c.n_opp_ants) continue;
         int d = OO;
         int b = 0;
         double k = 1.2*sum_of_my_ants < sum_of_opp_ants ? 0.5 : 1;
         for (int base : my_bases) {
            if (chmin(d, int(k*dist[base][i]))) b = base;
         }
         if (d != OO) dists.emplace_back(d, i, b);
      }
      sort(dists.begin(), dists.end());
      set<Query> queries;
      int myants = sum_of_my_ants;
      int egg_anken = 0;
      for (auto [d, i, base] : dists) {
         if (myants < d) continue;
         if (queries.size() >= 3 && turn < 5) break;
         Query q;
         q.type = 1;
         if (cells[i].type == EGG) egg_anken += 1;
         q.index1 = i;
         q.index2 = base;
         int oppd = OO; for (int b : opp_bases) chmin(oppd, dist[i][b]);
         q.strength = d + max(1, cells[i].n_opp_ants) + 10 + 30 - 0.85 * oppd;
         myants -= d;
         queries.insert(q);
      }

      if (sum_of_egg_ants == 0 && sum_of_eggs > 0 && turn <= 5 && fst) {
         fst = false;
         while (!queries.empty()) {
            queries.erase(queries.begin());
         }
         for (auto [d, i, base] : dists) {
            if (cells[i].type != EGG) continue;
            Query q;
            q.type = 1;
            q.index1 = i;
            q.index2 = base;
            q.strength = d + max(1, cells[i].n_opp_ants) + 10;
            queries.insert(q);
            break;
         }
      }

      if (queries.empty()) {
         for (auto [d, i, base] : dists) {
            if (myants < d * 1) continue;
            Query q;
            q.type = 1;
            q.index1 = i;
            q.index2 = base;
            q.strength = d + max(1, cells[i].n_opp_ants);
            myants -= d * 1;
            queries.insert(q);
         }
      }

      // フローで解きたかった
      vector beacons(n_cells, -1);
      set<int> visited;
      for (auto q : queries) {
         if (visited.count(q.index1)) continue;
         vector<int> route;
         int now = q.index2;
         while (now != -1) {
            route.push_back(now);
            now = preroute[q.index1][now];
         }
         for (auto v : route) {
            if (visited.count(v)) continue;
            chmax(beacons[v], q.strength);
            visited.insert(v);
         }
      }

      // vector<Query> outputs(queries.begin(), queries.end());
      vector<Query> outputs;
      rep (i, n_cells) {
         if (beacons[i] != -1) {
            Query q;
            q.type = 0;
            q.index = i;
            q.strength = beacons[i];
            outputs.push_back(q);
         }
      }
      {
         for (int b : my_bases) {
            Query q;
            q.type = 0;
            q.index = b;
            q.strength = 1;
            outputs.push_back(q);
         }
      }

      rep (i, outputs.size()) {
         auto& q = outputs[i];
         if (i != 0) cout << ';';
         switch (q.type) {
            case 0:
               cout << "BEACON " << q.index << ' ' << q.strength;
               break;
            case 1:
               cout << "LINE " << q.index1 << ' ' << q.index2 << ' ' << q.strength;
               break;
            case 2:
               cout << "WAIT";
               break;
            default:
               cout << "MESSAGE " << q.txt;
               break;
         }
         if (i == (int)outputs.size() - 1) cout << endl;
      }
   }

   return 0;
}
