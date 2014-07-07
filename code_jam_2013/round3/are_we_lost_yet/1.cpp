#include <iostream>
struct edge {
  unsigned int u;
  unsigned int v;
  unsigned int a;
  unsigned int b;
};
#include <vector>
typedef std::vector<edge> VE;
typedef std::vector<unsigned int> VU;
typedef std::vector<bool> VB;

bool is_bad_prefix(unsigned int N, VE &edges, VU &route, unsigned int prefix_size) {
  unsigned int M(edges.size()), P(route.size());

  VU distances(N); VB visited(N, false);
  distances[1 - 1] = 0; visited[1 - 1] = true;
  distances[2 - 1] = 0; visited[2 - 1] = true;
  for (unsigned int i2 = 1; i2 <= prefix_size; ++i2) {
    distances[2 - 1] += 2 * edges[route[i2 - 1] - 1].a;
    distances[edges[route[i2 - 1] - 1].v - 1] = distances[2 - 1];
    visited[edges[route[i2 - 1] - 1].v - 1] = true;
  }
  distances[2 - 1] -= 1;

  return false;
}

int main() {
  unsigned int T; std::cin >> T;
  for (unsigned int i1 = 1; i1 <= T; ++i1) {
    unsigned int N, M, P; std::cin >> N >> M >> P;
    VE edges(M);
    for (unsigned int i2 = 1; i2 <= M; ++i2) 
      std::cin >> edges[i2 - 1].u >> edges[i2 - 1].v >> edges[i2 - 1].a >> edges[i2 - 1].b;
    VU route(P);
    for (unsigned int i3 = 1; i3 <= P; ++i3) std::cin >> route[i3 - 1];
    unsigned int i4;
    for (i4 = 1; (i4 <= N) && is_bad_prefix(N, edges, route, i4); ++i4);
    

    std::cout << "Case #" << i1 << ": ";
    std::cout << "Looks Good To Me";
    std::cout << std::endl;
  }

  return 0;
}
