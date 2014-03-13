#include <iostream>
#include <vector>
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
#include <algorithm>

void dotestcase(int test_case) {
  int N, M;
  std::cin >> N >> M;
  VVI a(N, VI(M));
  for (int i1 = 0; i1 < N; ++i1) 
    for (int i2 = 0; i2 < M; ++i2) 
      std::cin >> a[i1][i2];
  VVI b(N, VI(M, 100));
  for (int i1 = 0; i1 < N; ++i1) {
    int temp1 = a[i1][0];
    for (int i2 = 1; i2 < M; ++i2) 
      temp1 = std::max(temp1, a[i1][i2]);
    for (int i2 = 0; i2 < M; ++i2)
      b[i1][i2] = std::min(b[i1][i2], temp1);
  }
  for (int i2 = 0; i2 < M; ++i2) {
    int temp1 = a[0][i2];
    for (int i1 = 1; i1 < N; ++i1) 
      temp1 = std::max(temp1, a[i1][i2]);
    for (int i1 = 0; i1 < N; ++i1)
      b[i1][i2] = std::min(b[i1][i2], temp1);
  }
  bool is_possible = true;
  for (int i1 = 0; is_possible && (i1 < N); ++i1) 
    for (int i2 = 0; is_possible && (i2 < M); ++i2) 
      is_possible = (a[i1][i2] == b[i1][i2]);
  // for (int i1 = 0; i1 < N; ++i1) {
  //   for (int i2 = 0; i2 < M; ++i2) 
  //     std::cout << b[i1][i2] << " ";
  //   std::cout << std::endl;
  // }
  std::cout << "Case #" << test_case << ": " << (is_possible ? "YES": "NO") << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    dotestcase(test_case);
  }

  return 0;
}
