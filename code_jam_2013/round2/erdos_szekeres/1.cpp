#include <iostream>
#include <vector>
typedef std::vector<unsigned int> VU;
typedef std::vector<VU> VVU;
#include <cassert>

void get_gt(unsigned int N, VU &A, VU &B, VVU &gt) {
  VU last_A(N, 0);
  for (unsigned int i1 = 1; i1 <= N; ++i1) {
    if (last_A[A[i1 - 1] - 1] >= 1) 
      gt[last_A[A[i1 - 1] - 1] - 1].push_back(i1);
    if (A[i1 - 1] >= 2) {
      assert(last_A[A[i1 - 1] - 2] >= 1);
      gt[i1 - 1].push_back(last_A[A[i1 - 1] - 2]);
    }
    last_A[A[i1 - 1] - 1] = i1;
  }
  VU last_B(N, N + 1);
  for (unsigned int i1 = N; i1 >= 1; --i1) {
    if (last_B[B[i1 - 1] - 1] <= N)
      gt[last_B[B[i1 - 1] - 1] - 1].push_back(i1);
    if (B[i1 - 1] >= 2) {
      assert(last_B[B[i1 - 1] - 2] <= N);
      gt[i1 - 1].push_back(last_B[B[i1 - 1] - 2]);
    }
    last_B[B[i1 - 1] - 1] = i1;
  }
}

void get_X(unsigned int N, VVU &gt, VU &locations, VU &X, unsigned int current) {
  if (X[current - 1] < 1) {
    for (unsigned int i3 = 1; i3 <= gt[current - 1].size(); ++i3)
      get_X(N, gt, locations, X, gt[current - 1][i3 - 1]);
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
    for (unsigned int i2 = 1; i2 <= N; ++i2) std::cin >> A[i2 - 1];
    for (unsigned int i2 = 1; i2 <= N; ++i2) std::cin >> B[i2 - 1];
    VVU gt(N);
    get_gt(N, A, B, gt);
    VU X(N, 0); {
      VU locations(N, 0);
      for (unsigned int i2 = 1; i2 <= N; ++i2) get_X(N, gt, locations, X, i2);
    } // {
    //   VU pseudo_A(N, 1);
    //   for (unsigned int i2 = 1; i2 <= N; ++i2) 
    // 	for (unsigned int i3 = 1; i3 < i2; ++i3) 
    // 	  if (X[i3 - 1] < X[i2 - 1] &&
    // 	      pseudo_A[i2 - 1] < (1 + pseudo_A[i3 - 1])) 
    // 	    pseudo_A[i2 - 1] = (1 + pseudo_A[i3 - 1]);
    //   VU pseudo_B(N, 1);
    //   for (unsigned int i2 = N; i2 >= 1; --i2) 
    // 	for (unsigned int i3 = N; i3 > i2; --i3) 
    // 	  if (X[i3 - 1] < X[i2 - 1] &&
    // 	      pseudo_B[i2 - 1] < (1 + pseudo_B[i3 - 1])) 
    // 	    pseudo_B[i2 - 1] = (1 + pseudo_B[i3 - 1]);
    //   for (unsigned int i2 = 1; i2 <= N; ++i2) {
    // 	if (A[i2 - 1] != pseudo_A[i2 - 1])
    // 	  std::cout << "i1 = " << i1 << ", i2 = " << i2 << ", A[i2 - 1] = " << A[i2 - 1] << ", pseudo_A[i2 - 1] = " << pseudo_A[i2 - 1] << std::endl;
    // 	if (B[i2 - 1] != pseudo_B[i2 - 1])
    // 	  std::cout << "i1 = " << i1 << ", i2 = " << i2 << ", B[i2 - 1] = " << B[i2 - 1] << ", pseudo_B[i2 - 1] = " << pseudo_B[i2 - 1] << std::endl;
    //   }
    // } 
    {
      std::cout << "Case #" << i1 << ":";
      for (unsigned int i2 = 1; i2 <= N; ++i2) std::cout << " " << X[i2 - 1];
      std::cout << std::endl;
    }
  }

  return 0;
}
