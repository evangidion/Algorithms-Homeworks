#include "the7.h"

int smin(std::vector<int>& mh, int times[], int n) {
    int s = 0;
    for(int i = 0; i < mh.size(); i++) {
        if(times[mh[s]] > times[mh[i]]) {
            s = i;
        }
    }
    int r = mh[s];
    mh.erase(mh.begin() + s);
    return r;
}

void dijkstra(int n, std::vector<Road> roads, int s, int e, long& cost, std::vector<int>& path) {
    std::vector<int> mh;
    int m = path.size();
    int times[n];
    int parent[n];
    for (int i = 0; i < n; i++) {
        mh.push_back(i);
        times[i] = INT_MAX;
        parent[i] = -1;
    }
    times[s] = 0;
    while(!mh.empty()) {
        int h = smin(mh, times, n);
        for(int i = 0; i < n; i++) {
            if(h != i) {
                for(int j = 0; j < roads.size(); j++) {
                    if((roads[j].endpoints.first == i && roads[j].endpoints.second == h) || (roads[j].endpoints.first == h && roads[j].endpoints.second == i)) {
                        int newTime = times[h] + roads[j].time;
                        if(times[i] == INT_MAX || times[i] >= newTime) {
                            times[i] = newTime;
                            parent[i] = h;
                        }
                    }
                }
            }
        }
    }
    int h = e;
    while(h != -1 && h!= s) {
        path.insert(path.begin() + m, h);
        h = parent[h];
    }
    cost += times[e];
}

void FindRoute(int n, std::vector<Road> roads, int s, int d, int x, int y) {
  // You can change these variables. These are here for demo only.
  std::vector<int> path1;
  std::vector<int> path2;
  path1.push_back(s);
  path2.push_back(s);
  long cost1 = 0;
  long cost2 = 0;
  dijkstra(n, roads, s, x, cost1, path1);
  dijkstra(n, roads, x, y, cost1, path1);
  dijkstra(n, roads, y, d, cost1, path1);
  dijkstra(n, roads, s, y, cost2, path2);
  dijkstra(n, roads, y, x, cost2, path2);
  dijkstra(n, roads, x, d, cost2, path2);
  if(cost1 <= cost2) {
      std::cout << cost1 << " ";
      PrintRange(path1.begin(), path1.end());
      std::cout << std::endl;
  }
  else {
      std::cout << cost2 << " ";
      PrintRange(path2.begin(), path2.end());
      std::cout << std::endl;
  }
  // Write your code here...
  
  // Your output should be like this. You can change this as long as you keep
  // the output format. PrintRange function helps you print elements of
  // containers with iteratos (e.g., std::vector).
  
}