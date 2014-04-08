#include <iostream>
#include <vector>
typedef std::vector<unsigned int> VU;
typedef std::vector<VU> VVU;
#include <cassert>

void get_lt(unsigned int N, VU &A, VU &B, VVU &lt) {
  VU last_A(N, 0);
  for (unsigned int i1 = 1; i1 <= N; ++i1) {
    if (last_A[i1 - 1] >= 1) 
      lt[last_A[i1 - 1] - 1].push_back(i1);
    if (A[i1] >= 2) {
      assert(last_A[A[i1] - 2] >= 1);
      lt[i1 - 1].push_back(last_A[A[i1] - 2]);
    }
    last_A[A[i1] - 1] = i1;
  }
  VU last_B(N, N + 1);
  for (unsigned int i1 = N; i1 >= 1; --i1) {
    if (last_B[i1 - 1] <= N)
      lt[last_B[i1 - 1] - 1].push_back(i1);
    if (B[i1] >= 2) {
      assert(last_B[B[i1] - 2] <= N);
      lt[i1 - 1].push_back(last_B[B[i1] - 2]);
    }
    last_B[B[i1] - 1] = i1;
  }
}

void get_X(unsigned int N, VVU &lt, VU &locations, VU &X, unsigned int current) {
  if (X[current - 1] < 1) {
    for (unsigned int i3 = 1; i3 <= lt[current - 1].size(); ++i3)
      get_X(N, lt, locations, X, lt[current - 1][i3 - 1]);
    unsigned int i4;
    for (i4 = 1; i4 <= N && locations[i4 - 1] >= 1; ++i4);
    assert(i4 <= N);
    X[current - 1] = i4;
    locations[i4 - 1] = current;
  }
}

int main () {
  unsigned int T;
  std::cin >> T;
  for (unsigned int i1 = 1; i1 <= T; ++i1) {
    unsigned int N;
    std::cin >> N;
    VU A(N), B(N);
    for (unsigned int i2 = 1; i2 <= N; ++i1) std::cin >> A[i2 - 1];
    for (unsigned int i2 = 1; i2 <= N; ++i1) std::cin >> B[i2 - 1];
    VVU lt(N);
    get_lt(N, A, B, lt);
    VU X(N, 0); {
      VU locations(N, 0);
      for (unsigned int i2 = 1; i2 <= N; ++i1) get_X(N, lt, locations, X, i2);
    }

    std::cout << "Case #" << i1 << ":";
    for (unsigned int i2 = 1; i2 <= N; ++i1) std::cout << " " << X[i2 - 1];
    std::cout << std::endl;
  }

  return 0;
}
