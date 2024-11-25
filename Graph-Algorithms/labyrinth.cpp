#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 1010;

char grid[MAXV][MAXV];
int n, m;
pair<int, int> s, dest;
vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char directions[] = {'R', 'L', 'D', 'U'};
vector<vector<int>> dist;
vector<vector<char>> path;

bool val(pair<int, int> u) {
    return u.first >= 0 && u.second >= 0 && u.first < n && u.second < m && grid[u.first][u.second] != '#';
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(s);
    dist[s.first][s.second] = 0;

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int movX = v.first + mov[i].first;
            int movY = v.second + mov[i].second;
            pair<int, int> u = {movX, movY};

            if (val(u) && dist[u.first][u.second] == INF) { 
                q.push(u);
                dist[u.first][u.second] = dist[v.first][v.second] + 1;
                path[u.first][u.second] = directions[i];

                if (u == dest) {
                    return;
                }
            }
        }
    }
}

string get_path() {
    string result;
    pair<int, int> current = dest;

    while (current != s) {
        result += path[current.first][current.second];
        if (path[current.first][current.second] == 'R') current.second--;
        else if (path[current.first][current.second] == 'L') current.second++;
        else if (path[current.first][current.second] == 'D') current.first--;
        else if (path[current.first][current.second] == 'U') current.first++;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    _ cin >> n >> m;
    dist = vector<vector<int>>(n, vector<int>(m, INF)); 
    path = vector<vector<char>>(n, vector<char>(m, 0)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                s = {i, j};
            if (grid[i][j] == 'B')
                dest = {i, j};
        }
    }

    bfs();

    if (dist[dest.first][dest.second] != INF) {  
        string path_str = get_path();
        cout << "YES" << endl;
        cout << dist[dest.first][dest.second] << endl;
        cout << path_str << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

