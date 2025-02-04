#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
  int n; cin >> n;
  vector<pair<pair<int, int>, int>> customers(n);
  
  for(int i = 0; i < n; i++){
    cin >> customers[i].first.first >> customers[i].first.second;
    customers[i].second = i;
  }
  sort(customers.begin(), customers.end());

  vector<int> roomsAssigned(n, -1);
  int roomId = 1;
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int,int> > > rooms;
 for(int i = 0; i < n; i++){
    if(rooms.size() == 0){
      roomsAssigned[customers[i].second] = roomId++;
      rooms.push({customers[i].first.second, roomId-1});
    } else {
      if(rooms.top().first < customers[i].first.first){
        roomsAssigned[customers[i].second] = rooms.top().second;
        pair<int, int> x = rooms.top();
        rooms.pop();
        rooms.push({customers[i].first.second, x.second});
      } else {
        roomsAssigned[customers[i].second] = roomId++;
        rooms.push({customers[i].first.second, roomId-1});
      }
    }
  } 
  cout << roomId-1 << endl;
  for(int i = 0; i < n; i++)
    cout << roomsAssigned[i] << " ";

  cout << endl;

  return 0;
}
